#!/usr/bin/ruby
gets
a=gets.split.map(&:to_f).each_cons(2).map{|x,y|y-x}
p a.reduce(:+)/a.size