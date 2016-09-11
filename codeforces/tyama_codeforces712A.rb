#!/usr/bin/ruby
gets;puts (gets.split.map(&:to_i)<<0).each_cons(2).map{|x,y|x+y}*' '