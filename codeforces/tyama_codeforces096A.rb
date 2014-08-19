#!/usr/bin/ruby
puts gets.chomp.chars.chunk{|e|e}.any?{|k,v|v.size>6} ? :YES : :NO