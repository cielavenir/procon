#!/usr/bin/ruby
#coding:utf-8

require 'stringio'

$sax=2
case $sax
	when 0
		require 'rexml/document'
		require 'rexml/parsers/streamparser' 
		require 'rexml/streamlistener'
	when 1
		require 'rexml/document'
		require 'rexml/parsers/sax2parser'
		require 'rexml/sax2listener'
	when 2
		begin
			require 'libxml'
		rescue LoadError
			#$stderr.puts 'Falling back to REXML. Please: gem install libxml-ruby'
			$sax=0
			require 'rexml/document'
			require 'rexml/parsers/streamparser' 
			require 'rexml/streamlistener'
		end
end

class AozoraListener
	case $sax
		when 0 then include REXML::StreamListener
		when 1 then include REXML::SAX2Listener
		when 2 then include LibXML::XML::SaxParser::Callbacks
	end

	def initialize
		super
		@in_main_text=false
		@main_text_div_depth=0
		@content=''
		@current_tag=[]
	end
	attr_reader :content

	def tag_start(tag,attrs)
		@current_tag.push(tag)
		h_attrs=Hash[*[attrs]]
		@in_main_text=true if tag=='div'&&h_attrs['class']=='main_text' #class="main_text"ならば本文
		@main_text_div_depth+=1 if @in_main_text&&tag=='div'
	end
	def start_element(uri,tag,qname,attrs) tag_start(tag,attrs) end
	alias_method :on_start_element, :tag_start
	def tag_end(tag)
		if (t=@current_tag.pop)!=tag then raise "xml is malformed /#{t}" end #タグの入れ子が誤っていたらエラーとする
		if @in_main_text&&tag=='div'
			@in_main_text=false if (@main_text_div_depth-=1)==0
		end
	end
	def end_element(uri,tag,qname) tag_end(tag) end
	alias_method :on_end_element, :tag_end
	def cdata(text)
	end
	alias_method :on_cdata_block, :cdata
	def text(txt)
		@content+=txt.gsub(/[\s\t　]/,'') if @in_main_text&&@main_text_div_depth==1&&!['rp','rt'].include?(@current_tag.last) #rp,rtの中なら捨てる
	end
	def characters(text) text(text) end
	alias_method :characters, :text
	alias_method :on_characters, :text
end

f=$<
listener=AozoraListener.new
case $sax
	when 0 then REXML::Parsers::StreamParser.new(f,listener).parse
	when 1 then parser=REXML::Parsers::SAX2Parser.new(f);parser.listen(listener);parser.parse
	when 2 then parser=LibXML::XML::SaxParser.io(f);parser.callbacks=listener;parser.parse
end
mecab_input=listener.content.encode('EUC-JP')
mecab_output=''

IO.popen('mecab -b 100000','r+b',external_encoding:'EUC-JP'){|io|
	io.puts mecab_input
	io.close_write
	mecab_output=io.read.encode('UTF-8')
}
#puts mecab_output
#exit
io=StringIO.new(mecab_output)
nouns=[]
verbs=[]
io.each{|e|
	e.chomp!
	break if e=='EOS'
	idx=e.index("\t")
	word=e[0...idx]
	meta=e.chomp[idx+1..-1].split(',')
	nouns<<word if meta[0]=='名詞' && meta[1]=='一般'
	verbs<<word if meta[0]=='動詞' && meta[1]=='自立'
}
nouns=nouns.sample(2)
puts "#{nouns[0]}は最近、#{nouns[1]}を#{verbs.sample}している。"