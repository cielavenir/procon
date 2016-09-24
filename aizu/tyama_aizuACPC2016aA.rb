#!/usr/bin/ruby
n,m,a,b,*d=$<.read.split.map(&:to_i)
d=d.take_while{|e|e>=a}.reverse
d=d.drop_while{|e|e<=b} if n-d.size<m
p d.size
