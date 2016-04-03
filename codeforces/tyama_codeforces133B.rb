#!/usr/bin/ruby
T='><+-.,[]'
r=0
gets.chomp.chars{|c|r=(r*16+8+T.index(c))%1000003}
p r