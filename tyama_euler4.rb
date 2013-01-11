#!/usr/bin/ruby
a=[]
999.step(0,-1){|i|999.step(i,-1){|j|s=i*j;if s==s.to_s.reverse.to_i then a.push(s) end}}
p a.max