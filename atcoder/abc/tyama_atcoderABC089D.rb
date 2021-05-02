#!/usr/bin/ruby
H,W,D=gets.split.map &:to_i
x=[0]*(H*W+1);y=[0]*(H*W+1);d=[0]*(H*W+1)
H.times{|i|gets.split.each_with_index{|e,j|x[e.to_i]=i;y[e.to_i]=j}}
(D+1..H*W).each{|i|d[i]=d[i-D]+(x[i]-x[i-D]).abs+(y[i]-y[i-D]).abs}
gets.to_i.times{x,y=gets.split.map &:to_i;p d[y]-d[x]}
