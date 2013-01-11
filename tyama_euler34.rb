#!/usr/bin/ruby
class Integer
	def fact
		ret=1
		2.step(self){|i|ret*=i}
		return ret
	end
end
p (11..999999).select{|i|i.to_s.split('').map{|e|e.to_i.fact}.reduce(&:+)==i}.reduce(&:+)