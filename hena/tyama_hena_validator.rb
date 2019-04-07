#!/usr/bin/env ruby
#coding:utf-8
require 'rubygems'
require 'multisax'
require 'net/http'
require 'uri'

def hena5(s)
	s.split(',').map{|e|e.scan(/../).sort}.sort
end

URLS={
	#'codeiq1'=>'codeiq/cardgame',
	'codeiq2'=>'codeiq/tetromino_bingo',
	#'codeiq3'=>'codeiq/octahedron', # IO is provided via text
	#below, IO is provided via text and you need to answer the false line.
	#'codeiq4'=>'codeiq/incseq',
	#'codeiq5'=>'codeiq/sumseq',
	#'codeiq6'=>'codeiq/unit',
	#'codeiq7'=>'codeiq/clatri',
	#'codeiq8'=>'codeiq/',

	'yokohamarb201410'=>'yokohamarb/2014.10.rotcell',
	'yokohamarb201607'=>'yokohamarb/2016.07.ront',
	'kanagawarb_evalex'=>'kanagawa.rb/evalex',

	'1'=>'hena/1',
	'2'=>'hena/ord2',
	'3'=>'hena/ord3ynode',
	'4'=>'hena/ord4tetroid',
	'5pre'=>'hena/ord5railsontiles',
	'5'=>'hena/ord5dahimi',
	'6pre'=>'hena/ord6lintersection',
	'6'=>'hena/ord6kinship',
	'7pre'=>'hena/ord7xysort',
	'7'=>'hena/ord7selectchair',
	'8pre'=>'hena/ord8entco',
	'8'=>'hena/ord8biboma',
	'9pre'=>'hena/ord9nummake',
	'9'=>'hena/ord9busfare',
	'10pre'=>'hena/ord10pokarest',
	'10'=>'hena/ord10haniwa',
	'11pre'=>'hena/ord11arithseq',
	'11'=>'hena/ord11bitamida',
	'12pre'=>'hena/ord12aloroturtle',
	'12'=>'hena/ord12rotdice',
	'13pre'=>'hena/ord13updowndouble',
	'13'=>'hena/ord13blocktup',
	'14pre'=>'hena/ord14crosscircle',
	'14'=>'hena/ord14linedung',
	'15pre'=>'hena/ord15subpalin',
	'15'=>'hena/ord15elebubo',
	'16pre'=>'hena/ord16lcove',
	'16'=>'hena/ord16boseg',
	'17pre'=>'hena/ord17scheherazade',
	'17'=>'hena/ord17foldcut',
	'18pre'=>'hena/ord18mafovafo',
	'18'=>'hena/ord18notfork',
	'19pre'=>'hena/ord19sanwa',
	'19'=>'hena/ord19nebasec',
	'20'=>'hena/ord20meetime',
	#'21'=>'http://d.hatena.ne.jp/torazuka/20140509/yhpg', #HTML on Blogs not supported.
	'22'=>'hena/ord22irrpas',
	'23'=>'hena/ord23snakemoinc',
	'24'=>'hena/ord24eliseq',
	'25'=>'hena/ord25rotcell',
	'26'=>'hena/ord26tribo',
	'27'=>'hena/ord27raswi',
	'28'=>'hena/ord28spirwa',
	'29'=>'hena/ord29devdice',
	'30'=>'hena/ord30taxi',
	'e01'=>'hena/orde01rotbk',
	'e02'=>'hena/orde02pire',
	'e03'=>'hena/orde03nofconv',
	#'e04'=>'http://mtsmfm.github.io/2016/06/04/doukaku-e04.html',
	'e05'=>'hena/orde05dokitruck',
	#'e06'=>'http://mtsmfm.github.io/2016/08/06/doukaku-e06.html',
	'e07'=>'hena/orde07_7seg',
	#'e08'=>'http://mtsmfm.github.io/2016/10/01/doukaku-e08.html',
	'e09'=>'hena/orde09_penwa',
	#'e10'=>'http://mtsmfm.github.io/2016/12/03/doukaku-e10.html',
	'f01'=>'hena/ordf01_twicel',
	'e11'=>'hena/orde11tredis',
	'f02'=>'hena/ordf02in2rec',
	#'e12'=>'http://mtsmfm.github.io/2017/03/04/doukaku-e12.html',
	'f03'=>'hena/ordf03triom',
	'e13'=>'hena/orde13hextet',
	'f04'=>'hena/ordf04octsp',
	'f05'=>'hena/ordf05rotblo',
	#'e14'=>'http://mtsmfm.github.io/2017/06/03/doukaku-e14.html',
	'e15'=>'hena/orde15nohil',
	'e16'=>'hena/orde16nontri',
	'e17'=>'hena/orde17palin',
	'f06'=>'hena/ordf06numit',
	'e18'=>'hena/orde18twintri',
	'f07'=>'hena/ordf07walk',
	#'e19'=>'https://mtsmfm.github.io/2017/11/04/doukaku-e19.html',
	'f08'=>'hena/ordf07chairs', # f07:genbun-mama
	'e20'=>'hena/orde20maze',
	'f09'=>'hena/ordf09rotbox',
	#'e21'=>'https://mtsmfm.github.io/2018/02/03/doukaku-e21.html',
	'e22'=>'hena/orde22numord',
	'f10'=>'hena/ordf10updown',
	'e23'=>'hena/orde23nokoch',
	'e24'=>'hena/orde24tancho',
	#'e25'=>'https://mtsmfm.github.io/2018/07/07/doukaku-e25.html',
	#'e26'=>'https://cedretaber.github.io/doukaku/e26/',
	'e27pre'=>'hena/orde27ligmir',
	'e27'=>'hena/orde27cardgame',
	'e28'=>'hena/orde28sqst',
	'e29'=>'hena/orde29unes',
	'e30'=>'hena/orde30sumt',
	'e31'=>'hena/orde31rotnum',
	'e32'=>'hena/orde32rects',
}
if ARGV.size<1
	puts 'validator program [identifier]'
	puts 'validator --list'
	puts 'If identifier is not present, I will use stdin.'
	exit
end

flag5=false
$flage27=false
if ARGV.size<2
	if ARGV[0]=='--list'
		URLS.each_key{|e|puts e}
		exit
	end
	body=STDIN.read
else
	if !URLS.has_key?(ARGV[1])
		puts 'URL wrong: '+ARGV[1]
		exit
	end
	flag5=true if ARGV[1]=='5'
	$flage27=true if ARGV[1]=='e27'
	uri=URI.parse('http://nabetani.sakura.ne.jp/'+URLS[ARGV[1]]+'/')
	body=''
	Net::HTTP.start(uri.host){|http|
		resp=http.get(uri.path)
		if resp.code!='200'
			puts 'Failed to download HTML'
			exit
		end
		body=resp.body
	}
end
#extracts the final table region
#table section contains only tags which are also valid as XML.
#also, th and td must not have tags inside.
body.force_encoding('UTF-8')
body.gsub!(/\<table class='bibo_s'\>.*?\<\/table\>/m,'table')
body.gsub!(/\<table cellspacing='0' class='scell'\>.*?\<\/table\>/m,'table')
body.gsub!(/\<div class='map'\>.*?\<\/div\>/m,'div')

body.gsub!(/\<td class='on'\>.*?\<\/td\>/m,'')
body.gsub!(/\<td class='off'\>.*?\<\/td\>/m,'')
body.gsub!(/\<td class='nolamp'\>.*?\<\/td\>/m,'')
body.gsub!(/\<td class='nazo'\>.*?\<\/td\>/m,'')
body.gsub!(/\<td class='nabe_digiback'\>.*?\<\/td\>/m,'')
body.gsub!(/\<td class='center'\>(.*?)\<\/td\>/m,'\1')
body.gsub!(/\<span class='card'\>.*?\<\/span\>/m,'')
body.gsub!(/\<tr\>\s*?\<\/tr\>/m,'')
body.gsub!(/\<table\>\s*?\<\/table\>/m,'table')

body.gsub!(/\<img[^\>]*\>/,'img')
body.gsub!(/\<a.*?\<\/a\>/m,'')
body.gsub!('状況へのリンク','')
body.gsub!('図へのリンク','')
body.gsub!('カードの分け方の例','')
body.gsub!('略','')
body.gsub!(/\<small.*?\<\/small\>/m,'')

xml='<table'+body.split('<table').last.split('</table>').first+'</table>'
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
		text = text.gsub('&nbsp;','').gsub('n/a','').gsub('/','') if $flage27
		if !text.empty?
			@content << text
			@fold+=1 if @first
		end
	end
	def sax_comment(text)
	end
}.new)
data=listener.content.each_slice(listener.fold).to_a
data=data.map{|e|e[(data[0][0]=='#')?1:0,2]}[1..-1]
IO.popen(ARGV[0],'r+b'){|io|
	data.each{|e|io.puts e[0]}
	io.close_write
	data.each_with_index{|e,i|
		print 'Case '+(i).to_s+': '
		puts (flag5 ? hena5(io.gets.chomp)==hena5(e[1]) : io.gets.chomp==e[1])?'OK':'NG'
	}
}
