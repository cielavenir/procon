#!/usr/bin/ruby
r,c=gets.split.map(&:to_i)
p (r*c-1)/(r==c ? 4 : 2)