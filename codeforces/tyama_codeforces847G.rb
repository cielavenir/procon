#!/usr/bin/ruby
gets;p$<.map{|e|e.chomp.chars}.transpose.map{|e|e.count('1')}.max
