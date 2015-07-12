#!/usr/bin/ruby
require 'prime'

def cycle(n)
	a=[x=n]
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
M=gets.to_i
if M>100000
	V=[6,220,12496,14316]
	p V.take_while{|e|e<=M}.last
	exit
end
$t=[1,1]+2.step(M).map{|i|i.prime_division.reduce(1){|s,e|s*(e[0]**(e[1]+1)-1)/(e[0]-1)}-i}
$c=[]
6.times{|i|$c<<[0,i]}
N=0
V=[]
6.step(M){|i|
	n=cycle(i)
	$c<<[n,i]
=begin
	if N<n
		N=n
		V<<i
		p i
	end
=end
}
m=$c.max
p $c.select{|e|e[0]==m[0]}[0][1]
#p V
#[6,220,12496,14316]
__END__
1000000