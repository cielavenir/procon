#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/orde23nokoch/
#https://qiita.com/Nabetani/items/77e7e2c749767f197c0e

T={'a'=>[0,1,-1,0],'b'=>[0,1,0,-1,0]}
STDOUT.sync=true
while gets
	n,s=$_.chomp.split(',')
	n=n.to_i-1
	q=0
	s.reverse.each_char{|c|
		n,r=n.divmod(T[c].size)
		q=(q+T[c][r])%3
	}
	if n>0
		puts 'x'
	else
		puts '0+-'[q]
	end
end
