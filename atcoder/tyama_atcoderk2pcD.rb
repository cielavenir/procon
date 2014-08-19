#!/usr/bin/ruby
k=gets.to_i
h=Hash.new{|h,k|h[k]={}}
p gets.to_i.times.map{gets.split.map(&:to_i)}.sort.reduce((2<<k)-1){|r,e|e[0].step(0,-1).none?{|i|h[i][(e[1]-1)>>(e[0]-i)]}?(h[e[0]][e[1]-1]=1;r-=(2<<(k-e[0]))-1):r}