#!/usr/bin/env ruby
require 'rubygems'
require 'multisax'
require 'net/http'
require 'uri'

URLS={
	'1'=>'1',
	'2'=>'ord2',
	'3'=>'ord3ynode',
	'4'=>'ord4tetroid',
	'5pre'=>'ord5railsontiles',
	'5'=>'ord5dahimi',
	'6pre'=>'ord6lintersection',
	'6'=>'ord6kinship',
	'7pre'=>'ord7xysort',
	'7'=>'ord7selectchair',
	'8pre'=>'ord8entco',
	'8'=>'ord8biboma',
	'9pre'=>'ord9nummake',
	'9'=>'ord9busfare',
	'10pre'=>'ord10pokarest',
	'10'=>'ord10haniwa',
	'11pre'=>'ord11arithseq',
	'11'=>'ord11bitamida',
	'12pre'=>'ord12aloroturtle',
	'12'=>'ord12rotdice',
	'13pre'=>'ord13updowndouble',
	'13'=>'ord13blocktup',
	'14pre'=>'ord14crosscircle',
	'14'=>'ord14linedung',
	'15pre'=>'ord15subpalin',
}
if ARGV.size<1
	puts 'validator program [identifier]'
	puts 'If identifier is not present, I will use stdin.'
end
if ARGV.size<2
	body=STDIN.read
else
	if !URLS.has_key?(ARGV[1])
		puts 'URL wrong: '+ARGV[1]
		exit
	end
	uri=URI.parse('http://nabetani.sakura.ne.jp/hena/'+URLS[ARGV[1]]+'/')
	body=''
	Net::HTTP.start(uri.host){|http|
		body=http.get(uri.path).body
	}
end
#table section contains only tags which are also valid as XML.
xml='<table'+body.split('<table').last.split('</table>').first+'</table>'
xml.gsub!(/\<img[^\>]*\>/,'img')
listener=MultiSAX::Sax.parse(xml,Class.new{
	include MultiSAX::Callbacks
	def initialize
		@content=[]
		@current_tag=[]
		@first=true
		@fold=0
	end
	attr_reader :content, :fold

	def sax_tag_start(tag,attrs)
		@current_tag.push(tag)
	end
	def sax_tag_end(tag)
		if (t=@current_tag.pop)!=tag then raise "xml is malformed /#{t}" end
		@first=false if t=='tr'
	end
	def sax_cdata(text)
	end
	def sax_text(text)
		text.strip!
		@content << text if text.size>0
		@fold+=1 if @first
	end
	def sax_comment(text)
	end
}.new)
data=listener.content.each_slice(listener.fold).to_a
data=data.map{|e|e[(data[0][0]=='#')?1:0,2]}[1..-1]
IO.popen(ARGV[0],'r+b'){|io|
	data.each_with_index{|e,i|
		io.puts e[0]
		puts 'Case '+(i+1).to_s+': '+(io.gets.chomp==e[1]?'OK':'NG')
	}
}