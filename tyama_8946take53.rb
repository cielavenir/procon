#!/usr/bin/ruby
raise "Ruby 1.9+ is required" if RUBY_VERSION<'1.9'
require 'exifr'

def zip(a)
	a.shift.zip(*a)
end
def zip_string(a) zip(a.map{|e|e.split('')}).map(&:join) end
#Stage1
a=[
	[0x1b,0x24,0x42,0x25,0x6d,0x21,0x3c,0x25,0x5e,0x3b,0x7a,0x1b,0x28,0x42].map(&:chr)*'',
	[0x1b,0x24,0x42,0x24,0x37,0x21,0x21,0x22,0x2a,0x21,0x21,0x1b,0x28,0x42,0x73,0x68,0x69].map(&:chr)*''
]
puts a.join("\n").encode(Encoding.default_external,'ISO-2022-JP') #し => shi
pass=[
	'10 10 10 10 10',
	'01 10 00 01 11',
	'10 01 00 00 01',
].map(&:split)
#pass.map!(&:reverse)
pass=pass.transpose.map{|e|e.join}*' ' #実際には形のまま読めば良い
puts pass # 100110 101001 100000 100100 101101 => たきあらし => takiarashi

#Stage2
#memo.jpg -> B君の地方の鶏の名前で漢字とカタカナの付くもの
gps=EXIFR::JPEG.new('../Downloads/Zimoto.jpg').gps
puts "open: https://maps.google.co.jp/maps?ll=#{gps.latitude},#{gps.longitude}" #高知 => 土佐ジロー