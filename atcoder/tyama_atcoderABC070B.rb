#!/usr/bin/ruby
a,b,c,d=gets.split.map &:to_i
p [[b,d].min-[a,c].max,0].max
