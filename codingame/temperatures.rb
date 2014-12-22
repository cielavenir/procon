#!/usr/bin/ruby
N = gets.to_i
if N==0
	p 0
else
	a=gets.split.map(&:to_i)
	if a.all?{|e|e<0}
		p a.max
	else
		p a.map(&:abs).min
	end
end