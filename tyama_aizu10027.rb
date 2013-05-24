#!/usr/bin/ruby
h=[[0,3],[1,1],[3,0]]
puts $<.drop(1).map{|e|h[e.chomp.split.reduce(:<=>)+1]}.transpose.map{|e|e.reduce(:+)}*' '