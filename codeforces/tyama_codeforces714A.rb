#!/usr/bin/ruby
a,b,c,d,e=gets.split.map &:to_i
a=[a,c].max
b=[b,d].min
p [0,b-a+1-(a<=e&&e<=b ? 1 : 0)].max