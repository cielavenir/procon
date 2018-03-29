#!/usr/bin/ruby
n,a,b=gets.split.map &:to_i
a-=1
b-=1
c=1
while a/2!=b/2
	a/=2
	b/=2
	c+=1
end
puts 1<<c==n ? 'Final!' : c
