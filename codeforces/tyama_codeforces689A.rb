#!/usr/bin/ruby
a=[true]*10
gets;gets.chomp.chars{|c|a[c.to_i]=false}
r=0
if [[1,2,3],[7,9,0],[1,4,7,0],[3,6,9,0]].none?{|e|e.all?{|i|a[i]}}
	puts :YES
else
	puts :NO
end