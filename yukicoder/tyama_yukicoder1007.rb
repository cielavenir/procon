#!/usr/bin/ruby
n,k,*a=`dd`.split.map &:to_i;k-=1
(p 0;exit)if a[k]==0
l=(k-1).downto(1).find{|i|a[i]<2||a[i-1]<1}||0
r=(k+1...n-1).find{|i|a[i]<2||a[i+1]<1}||n-1
p [a[l...k].sum,a[k+1..r].sum].send(a[k]>1?:sum: :max)+a[k]
