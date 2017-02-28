#!/usr/bin/ruby
class Integer
	def to_tern
		q=(self+1)/3
		r=(self+1)%3
		(q!=0 ? q.to_tern : "")+"-0+"[r]
	end
end
puts gets.to_i.to_tern
