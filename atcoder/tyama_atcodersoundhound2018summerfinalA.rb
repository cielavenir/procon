#!/usr/bin/ruby
c,d=gets.split.map &:to_i
r=0
k=10
(r+=[[k*170,d].min-[k*14,c].max,0].max;k*=2)while k*14<d
p r
