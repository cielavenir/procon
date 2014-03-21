#!/usr/bin/ruby
puts $<.drop(1).each_with_index.map{|e,i|e[i,1]}*''