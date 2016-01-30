#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_i).sort
p [a[0],*a.each_cons(2).map{|x,y|(y-x)/2},n-1-a[-1]].max