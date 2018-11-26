#!/usr/bin/ruby
n,*x=`dd`.split.map &:to_i
r=0
x.sort.each_with_index{|e,i|r+=e*(1+2*i-n)}
p r
