#!/usr/bin/ruby
p gets.split.map(&:to_i).sort.each_cons(2).map{|x,y|y-x}.min
