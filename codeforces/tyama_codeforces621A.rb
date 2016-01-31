#!/usr/bin/ruby
gets
x,y=gets.split.map(&:to_i).sort.reverse.partition{|e|e%2==0}
p x.reduce(0,:+)+y[0,y.size/2*2].reduce(0,:+)