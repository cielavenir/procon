#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i).sort.chunk{|e|e}.map{|k,v|[-v.size,-k]}.sort
p -a[0][1]