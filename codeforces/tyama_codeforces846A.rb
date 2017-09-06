#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
b=[0];c=[0]
a.each{|e|b<<b[-1]+(e==0 ? 1 : 0)}
a.reverse_each{|e|c.unshift c[0]+(e==1 ? 1 : 0)}
p n.times.map{|i|b[i+1]+c[i]}.max
