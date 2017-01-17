#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
x,y=[n,m].map{|e|e.times.map{gets.chomp}}
n+=1 if (x&y).size.odd?
puts [:NO,:YES,:NO][n<=>m]
