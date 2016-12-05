#!/usr/bin/ruby
R,C=gets.split.map &:to_i
r=0
C.step(R,C){|i|r+=((R*R-i*i)**0.5/C).to_i}
p r*4
