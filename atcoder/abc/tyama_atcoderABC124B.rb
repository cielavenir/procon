#!/usr/bin/ruby
n,m,*a=`dd`.split.map &:to_i
r=1
(n-1).times{|i|m<=a[i]&&(m=a[i];r+=1)}
p r
