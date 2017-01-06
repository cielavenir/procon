#!/usr/bin/ruby
gets
p gets.split.group_by{|e|e}.reduce(0){|s,(k,v)|s+v.size/2}
