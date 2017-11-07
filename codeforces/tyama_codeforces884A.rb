#!/usr/bin/ruby
n,t,*a=$<.read.split.map &:to_i
p (1..n).find{|i|0>=t-=86400-a[i-1]}
