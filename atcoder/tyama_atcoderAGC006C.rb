#!/usr/bin/ruby
n,*z=`dd`.split.map &:to_i
t=*0...n
*e=t
a=z.shift n+1
n.downto(1){|i|a[i]-=a[i-1]}
k,*z=z
z.map{|x|t[x-2,2]=t[x-1],t[x-2]}
60.times{|i|k[i]>0&&e.map!{|q|t[q]};t=t.map{|q|t[q]}}
k,*a=a;e.map{|q|p k;k+=a[q]}
