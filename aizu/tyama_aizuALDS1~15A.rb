#!/usr/bin/ruby
r=gets.to_i;k=0
[25,10,5,1].each{|e|d,r=r.divmod e;k+=d}
p k
