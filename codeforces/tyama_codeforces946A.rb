#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
x,y=a.partition{|e|e>0}
p x.reduce(0,:+)-y.reduce(0,:+)
