#!/usr/bin/ruby
f=->n{n%15==0?8:n%3==0||n%5==0?4:n.to_s.size}
r=0;gets.split.map{|e|r+=f[e.to_i]};p r
