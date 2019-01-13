#!/usr/bin/ruby
s=gets.chomp
puts [s[0,7],*(0..6).map{|i|s[0,i]+s[i-7..-1]}].any?{|e|e=='keyence'} ? 'YES' : 'NO'
