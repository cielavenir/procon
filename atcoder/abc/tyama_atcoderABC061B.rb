#!/usr/bin/ruby
n,m=gets.split.map &:to_i
r=[0]*-~n
m.times{
	a,b=gets.split.map &:to_i
	r[a]+=1
	r[b]+=1
}
puts r[1..-1]
