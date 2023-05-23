#!/usr/bin/ruby
Fixnum=Integer if !defined?(Fixnum)
class Fixnum
	#I want -3/2 to be -1, not -2
	def /(o) self.fdiv(o).truncate end
end
puts gets.to_i.times.map{eval gets.strip.chop}
