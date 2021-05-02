#!/usr/bin/ruby
n,k,m,r=gets.split.map &:to_i
s=$<.map(&:to_i).sort.reverse[0,k]
if s.reduce(0,:+)>=r*k
	p 0
	exit
end
s.pop if s.size==k
z=r*k-s.reduce(0,:+)
if z>m
	p -1
else
	p z
end