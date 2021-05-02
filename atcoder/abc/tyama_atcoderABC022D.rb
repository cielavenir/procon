#!/usr/bin/ruby
def f
	a=N.times.map{gets.split.map(&:to_f)}
	g=a.transpose.map{|e|e.reduce(:+)/a.size}
	a.map{|e|Math.hypot(*e.zip(g).map{|x,y|x-y})}.max
end
N=gets.to_i
p 1/f*f