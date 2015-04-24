#!/usr/bin/ruby
require 'date'
r=0
x=Date.new(2015)
while x.year<2016
	r+=1 if x.month==x.day.to_s.chars.map(&:to_i).reduce(:+)
	x+=1
end
p r