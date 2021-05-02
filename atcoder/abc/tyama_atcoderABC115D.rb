#!/usr/bin/ruby
n,x=gets.split.map &:to_i
a=[1];b=[1]
n.times{|i|a<<a[i]*2+3;b<<b[i]*2+1}
f=->n,x{n==0 ? x<=0?0:1 : x<=1+a[n-1] ? f[n-1,x-1] : b[n-1]+1+f[n-1,x-2-a[n-1]]}
p f[n,x]
