#!/usr/bin/ruby
n,x,*a=$<.map &:to_i;a=a.sort.reverse
p (1..n).find{|i|(x-=a[i-1])<=0}