#!/usr/bin/awk -f
n,*x=`dd`.split.map &:to_i
r=0
x.sort.each_with_index{|e,i|r+=1+2*i-n}
p r
