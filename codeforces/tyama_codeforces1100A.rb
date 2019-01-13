#!/usr/bin/ruby
n,k,*a=$<.read.split.map &:to_i
s=a.reduce :+
l=[0]*k
n.times{|i|l[i%k]+=a[i]}
p [(s-l.max).abs,(s-l.min).abs].max
