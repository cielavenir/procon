#!/usr/bin/ruby
x,y=gets.split.map{|e|e.to_i-1}
p (1..x+y).reduce(1,:*)/(1..x).reduce(1,:*)/(1..y).reduce(1,:*)