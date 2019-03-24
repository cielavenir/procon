#!/usr/bin/ruby
a,b,c,d=gets.split.map &:to_i
p (b-a+1)*(d-c+1)-[0,[b,d].min-[a,c].max+1].max
