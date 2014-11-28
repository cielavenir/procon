#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i).group_by{|e|e}.map{|k,v|[-v.size,-k]}.sort
p -a[0][1]