#!/usr/bin/ruby
s=gets.chomp
t=gets.chomp
puts (s.length-t.length+1).times.map{|i|s[i,t.length]==t && i+1}.select{|e|e}*' '