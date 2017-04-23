#!/usr/bin/ruby
n,*a=$<.read.split.map(&:to_i)
b=a.sort.each_cons(2).map{|x,y|y-x}
m=b.min
puts '%d %d'%[m,b.count(m)]
