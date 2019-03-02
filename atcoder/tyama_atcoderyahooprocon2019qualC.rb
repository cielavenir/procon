#!/usr/bin/ruby
k,a,b=gets.split.map &:to_i
t=k-a+1
p [k+1,t/2*(b-a)+t%2+a].max
