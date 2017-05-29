#!/usr/bin/ruby
puts$<.map(&:chomp).group_by{|e|e}.max_by{|k,v|v.size}[0]
