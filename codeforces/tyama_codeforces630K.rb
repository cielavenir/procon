#!/usr/bin/ruby
f=->n{(2..10).all?{|e|n%e!=0}}
g=->n{(1..n).count{|e|f[e]}}
d,r=gets.to_i.divmod(2520)
p g[2520]*d+g[r]