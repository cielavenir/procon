#!/usr/bin/ruby
a,b,c,*z=gets.split.map(&:to_i)
p [a,b,c].sort.zip(z.sort).reduce(0){|s,(p,q)|s+(p-q).abs}