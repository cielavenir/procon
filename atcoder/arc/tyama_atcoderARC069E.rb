#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
r=[0]*n
m=1e9
x,y=a.each_with_index.sort_by{|e,i|[-e,i]}.transpose
n.times{|i|r[m=[m,y[i]].min]+=-~i*(x[i]-x[i+1].to_i)}
p *r
