#!/usr/bin/ruby
n,s,*v=$<.read.split.map &:to_i
p [[(v.reduce(:+)-s)/n,*v].min,-1].max
