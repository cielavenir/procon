#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i
p (c/b+=a-1)*a+[c%b,a].min
