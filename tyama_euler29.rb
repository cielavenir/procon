#!/usr/bin/ruby
h={}
2.step(100){|a|2.step(100){|b|h[a**b]=1}}
p h.size