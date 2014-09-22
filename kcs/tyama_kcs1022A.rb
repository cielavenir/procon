#!/usr/bin/ruby
t=80*60
a=gets.to_i.times.map{
	a,b=gets.split.map(&:to_i)
	a*60+b
}.sort
n=0
while !a.empty?&&a[0]<=t
	t-=a[0]+3
	a.shift
	n+=1
end
p n