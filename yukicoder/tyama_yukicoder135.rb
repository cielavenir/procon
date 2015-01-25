#!/usr/bin/ruby
gets
p gets.split.map(&:to_i).sort.each_cons(2).map{|x,y|y-x}.select{|e|e>0}.min||0