#!/usr/bin/ruby
a,b,c,d=gets.split.map &:to_i
c+=~-a*d
p (c/60+b)%24,c%60