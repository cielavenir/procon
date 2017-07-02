#!/usr/bin/ruby
w,h=gets.split.map &:to_i
p -~w*-~h-(w*h%2>0?[w,h].min: w%2>0?w:h%2>0?h:[w,h].max+(w==h ?1:0))
