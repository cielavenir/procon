#!/usr/bin/ruby
A=[2,3,5,7,11,13]
B=[4,6,8,9,10,12]
P,C=gets.split.map(&:to_i)
h={1=>1.0}
P.times{
	x=Hash.new(0)
	h.each{|k,v|A.each{|e|x[k*e]+=v/6.0}}
	h=x
}
C.times{
	x=Hash.new(0)
	h.each{|k,v|B.each{|e|x[k*e]+=v/6.0}}
	h=x
}
p h.reduce(0){|s,(k,v)|s+=k*v}