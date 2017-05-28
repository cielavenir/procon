#!/usr/bin/ruby
n,k,*a=$<.read.split.map &:to_i
p [0,(k*2-1)*n-a.reduce(:+)*2].max
