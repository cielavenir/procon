#!/usr/bin/ruby
a,b=$<.map{|e|e.chomp.bytes}
puts a.size.times.any?{|i|a.rotate(i)==b} ? :Yes : :No
