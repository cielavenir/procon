#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i)
while !a.empty?
	p a.size
	m=a.min
	a=a.map{|e|e-m}.select{|e|e>0}
end