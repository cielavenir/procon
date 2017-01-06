#!/usr/bin/ruby
s=gets.chomp
l=s.size
t='SOS'*(l/3)
p l.times.count{|i|s[i]!=t[i]}
