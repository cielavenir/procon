#!/usr/bin/ruby
a,b=gets.split.map &:to_i
r=[*1..b]
a.times{x,y=gets.split.map &:to_i;r-=[*x..y]}
p r.size
puts r*' '
