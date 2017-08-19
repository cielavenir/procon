#!/usr/bin/ruby
n,k,*a=$<.read.split.map &:to_i
s=c=0
p (1..n).find{|i|s+=a[i-1];x=[s,8].min;s-=x;k<=c+=x}||-1
