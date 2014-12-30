#!/usr/bin/ruby
a=gets.to_i.times.map{gets.chomp}.sort
r=a.map(&:size).reduce(:+)
a.each_cons(2){|x,y|
	siz=[x.size,y.size].min
	r-=siz.times.find{|i|x[i]!=y[i]}||siz
}
p r