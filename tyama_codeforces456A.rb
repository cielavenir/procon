#!/usr/bin/ruby
a=gets.to_i.times.map{gets.split.map(&:to_i)}.sort
puts (a.each_cons(2).any?{|x,y|x[1]>y[1]} ? 'Happy' : 'Poor')+' Alex'