#!/usr/bin/ruby
n,f=gets.split.map(&:to_i)
r=f
n.times{
	a,b=gets.split.map(&:to_i)
	r=[r,[f-a,b].max+a].max
}
p r