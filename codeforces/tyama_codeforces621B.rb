#!/usr/bin/ruby
r=0
h1=Hash.new(0)
h2=Hash.new(0)
gets.to_i.times{
	x,y=gets.split.map(&:to_i)
	r+=h1[x-y]
	h1[x-y]+=1
	r+=h2[x+y]
	h2[x+y]+=1
}
p r