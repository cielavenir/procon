#!/usr/bin/ruby
def max_overlap(x,y)
	return x if x.include?(y)
	return y if y.include?(x)
	n=[x.size,y.size].min
	i1=(1...n).select{|i|x[-i..-1]==y[0,i]}.max||0
	x+y[i1..-1]
end

a=gets.to_i.times.map{gets.chomp}
p a.permutation.map{|b|
	b.reduce{|s,e|max_overlap(s,e)}.size
}.min