#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i)
p [0,a.count(1)*2-1-a.each_cons(2).count{|x,y|x==1&&y==1}].max