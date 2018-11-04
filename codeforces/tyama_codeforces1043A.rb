#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
p [*a,2*a.reduce(:+)/n+1].max
