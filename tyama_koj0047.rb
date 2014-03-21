#!/usr/bin/ruby
puts gets.chomp.split('').each_slice(2).map{|e|e.reverse}*''