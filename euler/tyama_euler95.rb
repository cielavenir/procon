#!/usr/bin/ruby
require 'prime'

def cycle(n)
	a=[n,x=$t[n]]
	loop{
		return 0 if x<2 || M<x
		x=$t[x]
		if idx=a.index(x)
			return a.size if idx==0
			return 0 if idx>0
		end
		a.push x
	}
end
M=gets.to_i-1
$t=[1,1]+2.step(M).map{|i|i.prime_division.reduce(1){|s,e|s*(e[0]**(e[1]+1)-1)/(e[0]-1)}-i}
$c=[]
6.times{|i|$c<<[cycle(i),i]}
6.step(M){|i|$c<<[cycle(i),i]}
m=$c.max
p $c.select{|e|e[0]==m[0]}[0][1]
__END__
1000000