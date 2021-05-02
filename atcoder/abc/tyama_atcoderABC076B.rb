#!/usr/bin/ruby
n,k=$<.map &:to_i
r=1
n.times{r=[r*2,r+k].min}
p r
