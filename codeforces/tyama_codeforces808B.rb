#!/usr/bin/ruby
n,k,*a=$<.read.split.map(&:to_i)
s=0.0
(k-1).times{|i|s+=a[i]}
r=0
(k-1...n).each{|i|s+=a[i];r+=s;s-=a[i-k+1]}
p r/(n-k+1)
