#!/usr/bin/ruby
require 'rational'
class Integer
	def lcm(n) self/self.gcd(n)*n end
end
while(a=gets.split.map(&:to_i)).size>1
a.shift
m=a.pop
g=a.shift(2)
fizzbuzz=g[0].lcm(g[1])
a=a.map{|e|fizzbuzz.lcm(e)/fizzbuzz}.uniq
if a.include?(1) then puts :NA;next end
if a.all?{|e|e>m} then puts fizzbuzz*m%1000003;next end
#a.select!{|e|e<=m}
c=d=0
while c<m
	d+=1
	c+=1 if a.none?{|e|d%e==0}
end
puts fizzbuzz*d%1000003
end