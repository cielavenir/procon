#!/usr/bin/ruby
gets;p gets.split.map(&:to_i).group_by{|e|e}.sort_by{|k,v|[-v.size,-k]}[0][0]