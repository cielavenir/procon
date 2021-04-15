#!/usr/bin/ruby
class Integer
	def isqrt
		return 0 if self<=0
		return 1 if self<4 # 1
		x,y=0,self
		while x!=y&&x+1!=y
			x,y=y,(self/y+y)/2
		end
		x
	end
end
n=gets.to_i
s=gets.chomp
c=s.count 'Q'
if s.include?('H')||c<1||c.isqrt**2!=c
	p -1;exit
end
a=s.chars.each_slice(n/c.isqrt).to_a
if a.any?{|e|e!=a[0]}
	p -1;exit
end
puts a[0]*''
