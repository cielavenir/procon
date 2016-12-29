#!/usr/bin/ruby
n,k,*a=`dd`.split.map &:to_i
a=(b=[0])+a
1.upto(a.size-1){|i|b[i]=b[i-1]+[0,a[i]].max;a[i]+=a[i-1]}
p (k...a.size).map{|i|b[-1]-b[i]+b[i-k]+[a[i]-a[i-k],0].max}.max
