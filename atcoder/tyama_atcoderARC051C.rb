#!/usr/bin/env ruby
class Numeric
	def to_i64() self.to_i end
end
data=ARGF.each_line.map{|l|l.split.map{|e|e.to_i.to_i64}}.to_a
n,a,b=data.shift
s=data[0]
m=1000000007
s.sort!
if a>1
	d=s[-1]
	while s[0]<d && b>0
		s[0]*=a
		b-=1
		s.sort!
	end
	(b%n).times{|i|s[i]=s[i]%m*a}
	s.rotate!(b%n)
	b/=n
	z=1
	while b>0
		z=a*z%m if b%2>0
		a=a*a%m
		b/=2
	end
	s=s.map{|e|e%m*z%m}
end
puts s.join("\n")