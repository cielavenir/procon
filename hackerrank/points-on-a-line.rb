#!/usr/bin/ruby
gets;a=$<.map{|e|e.split.map(&:to_i)}
puts a.all?{|x,y|x==a[0][0]}||a.all?{|x,y|y==a[0][1]} ? :YES : :NO
