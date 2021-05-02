#!/usr/bin/ruby
R=[]
n,*a=`dd`.split.map &:to_i
n.times{R<<1;(1...n).map{|i|
a[i-1]>a[i]&&(R<<n-1;a[i-1],a[i]=a[i],a[i-1])
R<<1
}}
p R.size,*R
