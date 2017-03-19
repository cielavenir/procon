#!/usr/bin/ruby
n,k,*a=`dd`.split.map &:to_i
a.sort_by! &:-@
s=r=0
n.times{|i|(k<=s+=a[i])&&(r=i+1;s-=a[i])}
p n-r
