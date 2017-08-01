#!/usr/bin/ruby
a,b,c,d,e=gets.split.map &:to_i;puts [:Friendship,:Second,:First][a*b+2*d<=>a*c+2*e]
