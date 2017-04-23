#!/usr/bin/ruby
a=gets.to_i.times.map{gets.chomp.chars}
l=a[0].size
b=a.map{|e|
	idx=(0...l).select{|i|e.rotate(i)==a[0]}
	if idx.empty?
		p -1
		exit
	end
	idx
}
p (0...l).map{|i|b.map{|e|e.map{|f|(f+i)%l}.min}.reduce(:+)}.min
