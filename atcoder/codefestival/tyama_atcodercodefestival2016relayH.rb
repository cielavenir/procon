#!/usr/bin/ruby
A=[c=0]*(2*D=86400)
gets.to_i.times{
	a,b=gets.split.map &:to_i
	A[c=(c+a)%D]+=1
	A[c+D]+=1
	c=(c+b)%D
}
(D*2-1).times{|i|A[i+1]+=A[i]}
p D.times.map{|i|A[i+10801]-A[i]}.max
