#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i
p [b+c-a,0].max
