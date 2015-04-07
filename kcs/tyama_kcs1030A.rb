#!/usr/bin/ruby
class Fixnum
	#I want -3/2 to be -1, not -2
	def /(o) self.fdiv(o).truncate end
end
a,b=gets.split.map(&:to_i)
puts [:+,:-,:*,:/].map{|e|a.send(e,b)}*' '