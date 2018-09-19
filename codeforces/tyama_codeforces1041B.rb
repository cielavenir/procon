#!/usr/bin/ruby
a,b,x,y=gets.split.map &:to_i;g=x.gcd y;p [a*g/x,b*g/y].min
