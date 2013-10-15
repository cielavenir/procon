#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/24b9be4ee3bae4c89a95
#http://nabetani.sakura.ne.jp/hena/ord8entco/
T={
	'000'=>'t',
	'0010'=>'s',
	'0011'=>'n',
	'0100'=>'i',
	'01010'=>'d',
	'0101101'=>'c',
	'010111'=>'l',
	'0110'=>'o',
	'0111'=>'a',
	'10'=>'e',
	'1100'=>'r',
	'1101'=>'h',
	'111'=>:eof,
}

STDOUT.sync=true
def solve(l)
	idx=0
	r=''
	loop{
		s=T.keys.find{|e|l[idx..-1].start_with?(e)}
		return '*invalid*' if !s
		idx+=s.size
		break if T[s]==:eof
		r+=T[s]
	}
	r+':'+idx.to_s
end
while gets
	puts solve($_.chomp.chars.map{|e|('%04b'%e.to_i(16)).reverse}*'')
end