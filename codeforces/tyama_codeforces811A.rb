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

a,b=gets.split.map &:to_i
a=a.isqrt
puts [:Vladik,:Valera,:Vladik][a*-~a<=>b]
