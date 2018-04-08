#!/usr/bin/ruby
n,m,*a=$<.read.split.map &:to_i
x=[0]*n
a.each{|e|x[e-1]+=1}
p x.min
