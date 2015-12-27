#!/usr/bin/ruby
gets
a=gets.split.each_with_index.map{|e,i|[e.to_i,i]}.sort.map(&:last)
p a.each_cons(2).reduce(0){|s,(x,y)|s+(x-y).abs}