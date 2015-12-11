#!/usr/bin/ruby
s=gets.chomp
t='PER'*(s.size/3)
p s.size.times.count{|i|s[i]!=t[i]}