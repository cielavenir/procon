#!/usr/bin/ruby
s=gets.chomp
p s.size.times.map{|i|s[i..-1]+s[0,i]}.uniq.size
