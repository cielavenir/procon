#!/usr/bin/ruby
puts (gets.chomp.reverse.chars.each_slice(3).map{|e|e*''}*',').reverse
