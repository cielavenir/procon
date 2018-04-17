#!/usr/bin/ruby
n,m,x,*a=`dd`.split.map &:to_i
idx=(0...m).bsearch{|i|a[i]>=x}||m
p [idx,m-idx].min
