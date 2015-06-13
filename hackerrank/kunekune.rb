#!/usr/bin/ruby
x,y=gets.split.map{|e|e.to_i.abs}
p (y>x ? y-x+1 : x-y)/2*2 + x+y