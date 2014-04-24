#!/usr/bin/ruby
#coding:utf-8

require 'stringio'

# MultiSAX: Ruby Gem to handle multiple SAX libraries
# https://github.com/cielavenir/multisax
module MultiSAX # minimal version
	class SAX
		@parser=nil
		def open(*list)
			list=[:libxml,:rexmlstream] if list.size==0
			list.each{|e_module|
				case e_module
					when :libxml
						begin
							require 'rubygems'
							require 'libxml'
						rescue LoadError;next end
						@parser=e_module;break
					when :rexmlstream
						require 'rexml/document'
						require 'rexml/parsers/streamparser'
						require 'rexml/streamlistener'
						@parser=e_module;break
				end
			}
			@parser
		end
		def reset() @parser=nil;@saxmodule=nil end

		def parse(source,listener)
			open if !@parser
			case @parser
				when :libxml
					listener.instance_eval{
						extend LibXML::XML::SaxParser::Callbacks
						alias :on_start_element :sax_tag_start
						alias :on_end_element :sax_tag_end
						alias :on_cdata_block :sax_cdata
						alias :on_characters :sax_text
						alias :on_comment :sax_comment
					}
				when :rexmlstream
					listener.instance_eval{
						extend REXML::StreamListener
						alias :tag_start :sax_tag_start
						alias :tag_end :sax_tag_end
						alias :cdata :sax_cdata
						alias :text :sax_text
						alias :comment :sax_comment
					}
			end

			if source.is_a?(String)
				case @parser
					when :libxml       then parser=LibXML::XML::SaxParser.string(source);parser.callbacks=listener;parser.parse
					when :rexmlstream  then REXML::Parsers::StreamParser.new(source,listener).parse
				end
			else
				case @parser
					when :libxml       then parser=LibXML::XML::SaxParser.io(source);parser.callbacks=listener;parser.parse
					when :rexmlstream  then REXML::Parsers::StreamParser.new(source,listener).parse
				end
			end
			listener
		end

	end
	Sax=SAX.new

	module Callbacks
		def sax_tag_start(tag,attrs) end
		def sax_tag_end(tag) end
		def sax_comment(text) end
		def sax_cdata(text) end
		def sax_text(text) end
	end
end

listener=MultiSAX::Sax.parse($<,Class.new{
	include MultiSAX::Callbacks
	def initialize
		@in_main_text=false
		@main_text_div_depth=0
		@content=''
		@current_tag=[]
	end
	attr_reader :content

	def sax_tag_start(tag,attrs)
		@current_tag.push(tag)
		h_attrs=Hash[*[attrs]]
		@in_main_text=true if tag=='div'&&h_attrs['class']=='main_text' #class="main_text"ならば本文
		@main_text_div_depth+=1 if @in_main_text&&tag=='div'
	end
	def sax_tag_end(tag)
		if (t=@current_tag.pop)!=tag then raise "xml is malformed /#{t}" end #タグの入れ子が誤っていたらエラーとする
		if @in_main_text&&tag=='div'
			@in_main_text=false if (@main_text_div_depth-=1)==0
		end
	end
	def sax_text(txt)
		@content+=txt.gsub(/[\s\t　]/,'') if @in_main_text&&@main_text_div_depth==1&&!['rp','rt'].include?(@current_tag.last) #rp,rtの中なら捨てる
	end
}.new)

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