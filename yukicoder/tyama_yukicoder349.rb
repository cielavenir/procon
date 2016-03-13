#!/usr/bin/ruby
n=gets.to_i
puts $<.group_by{|e|e}.map{|k,v|v.size}.max>-~n/2 ? :NO : :YES