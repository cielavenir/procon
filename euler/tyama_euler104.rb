#!/usr/bin/ruby
class String
	def pan?
		if self.size!=9 then return false end
		return 1.step(self.size).all?{|i|self.index(i.to_s)} ? true : false
	end
end
a=1;b=1;i=2
loop{
	c=a+b;i+=1
	if c>10**9
		s=(c%10**9).to_s
		if s.pan?
			s=c.to_s[0..8]
			if s.pan? then p i;exit end
		end
	end
	a=b;b=c
}