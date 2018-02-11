#!/usr/bin/ruby
a,b=gets.split.map &:to_i
p (a+10**b)/10**b*10**b
