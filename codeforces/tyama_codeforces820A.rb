#!/usr/bin/ruby
n,v0,v1,a,l=gets.split.map &:to_i
v=v0
i=0
while n>0
	n+=l if i>0
	n-=v
	i+=1
	v=[v+a,v1].min
end
p i
