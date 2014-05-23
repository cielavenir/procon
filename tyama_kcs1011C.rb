#!/usr/bin/ruby
puts gets.chomp.split('').select{|e|('0'..'9').include?(e)}.join.to_i.to_s(2)