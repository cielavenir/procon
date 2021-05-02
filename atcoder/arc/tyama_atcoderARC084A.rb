#!/usr/bin/ruby
a=$<.map{|e|e.chomp.chars}
puts a==a.reverse.map(&:reverse) ? :YES : :NO
