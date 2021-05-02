#!/usr/bin/ruby
N=gets.to_i
a=gets.split.map(&:to_i)
X=a.reduce(:+)
if X%N>0
	p -1
	exit
end
r=n=0
a.each{|e|
	n+=e-X/N
	r+=1 if n!=0
}
p r