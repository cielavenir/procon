#!/usr/bin/ruby
gets;a=gets.split.map &:to_i;p a.each_cons(2).map{|x,y|y-x}.min,a[-1]-a[0]
