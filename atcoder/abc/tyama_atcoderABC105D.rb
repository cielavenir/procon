#!/usr/bin/ruby
n,m,*a=`dd`.split.map &:to_i
h=Hash.new r=s=0
h[0]=1
a.map{|e|s=(s+e)%m;r+=h[s];h[s]+=1}
p r
