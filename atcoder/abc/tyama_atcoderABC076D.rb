#!/usr/bin/ruby
n,*t=`dd`.split.map &:to_i
v=t.map!{|e|e*2}.pop n
z=[0]*10**5
q=j=s=m=0
n.times{|i|z[j]=[z[j],v[i]].min;(j+1..j=q+=t[i]).map{|k|z[k]=[z[k-1]+1,v[i]].min}}
(j-1).downto(0){|i|s+=m=[m+1,z[i]].min}
p s/4.0
