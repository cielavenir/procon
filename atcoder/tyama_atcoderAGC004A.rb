#!/usr/bin/ruby
a=gets.split.map(&:to_i).sort
if a.any?(&:even?)
	p 0
else
	p a[0]*a[1]
end