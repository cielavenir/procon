#!/usr/bin/ruby
n,k,*b=`dd`.split.map &:to_i
a=[0]*-~n
s=-1<<60
n.times{|i|i<k-1||s=[s,a[i-k+1]].max;a[i+1]=[a[i]+b[i],s].max}
p a[n]
