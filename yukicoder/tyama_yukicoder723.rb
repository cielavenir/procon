#!/usr/bin/ruby
n,x,*a=`dd`.split.map &:to_i
h=Hash.new 0
r=0
a.map{|e|h[e]+=1}
a.map{|e|r+=h[x-e]}
p r
