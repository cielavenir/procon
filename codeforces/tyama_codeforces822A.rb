#!/usr/bin/ruby
a,b=gets.split.map &:to_i
p (1..[a,b].min).reduce :*
