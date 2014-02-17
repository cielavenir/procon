#!/usr/bin/ruby
puts $<.map{|e|e.chomp.split.reverse*' '}.reverse