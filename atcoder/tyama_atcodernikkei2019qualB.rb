#!/usr/bin/ruby
gets
r=0
a=$<.map{|e|e.chomp.chars}.transpose
a.each{|e|r+=e.uniq.size-1}
p r
