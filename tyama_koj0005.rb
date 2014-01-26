#!/usr/bin/ruby
require 'rational'
while(a=gets.split.map(&:to_i)).size>1
a.shift
m=a.pop
g=a.shift(2)
fizzbuzz=g[0].lcm(g[1])
if a.any?{|e|fizzbuzz%e==0} then puts :NA;next end
c=d=0
while c<m
	d+=fizzbuzz
	c+=1 if a.none?{|e|d%e==0}
end
puts d%1000003
end