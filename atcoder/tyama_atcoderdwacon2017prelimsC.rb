#!/usr/bin/ruby
M=4
n,*a=`dd`.split.map &:to_i
h=Hash.new 0
a.each{|e|h[e]+=1}
p a.count{|e|
	next if h[e]==0
	h[e]-=1
	M.downto(1){|i|(h[i]-=1;e+=i)while h[i]>0&&e+i<=M}
}
