#!/usr/bin/ruby
x,y=gets.split.map(&:to_i)
a=[y]*3
r=0
while a[0]!=x
	a[0]=[a[1]+a[2]-1,x].min
	a.sort!
	r+=1
end
p r