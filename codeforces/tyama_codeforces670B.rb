#!/usr/bin/ruby
n,k,*a=$<.read.split.map(&:to_i)
i=1
(k-=i;i+=1)while k>i
p a[k-1]
