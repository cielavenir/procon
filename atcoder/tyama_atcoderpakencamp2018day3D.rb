#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
x=[0]*n
(n-2).downto(0){|i|x[i]=[x[i+1]+a[i],0].max}
puts [0,x[0]].max
a<<0
0.upto(n-2){|i|puts [a[i]=[a[i]+a[i-1],0].max,x[i+1]].max}
