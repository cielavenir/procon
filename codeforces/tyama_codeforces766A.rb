#!/usr/bin/ruby
a,b=$<.map &:chomp
p a==b ? -1 : [a.size,b.size].max
