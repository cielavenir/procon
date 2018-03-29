#!/usr/bin/ruby
a,b=$<.map &:to_i
p ((a-b).abs+1)**2/4
