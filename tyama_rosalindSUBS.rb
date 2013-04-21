#!/usr/bin/ruby
s=gets.chomp
t=gets.chomp
puts (s.size-t.size+1).times.map{|i|s[i,t.size]==t && i+1}.select{|e|e}*' '