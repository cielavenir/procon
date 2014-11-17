#!/usr/bin/ruby
v=['x']*4
n=gets.to_i
v[n]='o'
gets.to_i.times{
	a,b=gets.split.map(&:to_i)
	v[a],v[b]=v[b],v[a]
}
p v.index('o')