#!/usr/bin/ruby
r=k=0
n,c=gets.split.map &:to_i
x,v=n.times.map{gets.split.map &:to_i}.transpose
l=v.reduce :+
(n-1).downto(m=0){|i|l-=v[i];r+=v[i];k=[k,l-x[i-1]*(i>0?2:0)+m=[m,r-c+x[i]].max].max}
m=0;n.times{|i|l+=v[i];r-=v[i];k=[k,r-(c-(x[i+1]||0))*(i<n-1?2:0)+m=[m,l-x[i]].max].max}
p k
