#!/usr/bin/ruby
f=[0,1]
2.step(99){|i|f<<f[i-1]+f[i-2]}
p 1.step(12).reduce(0){|s,i|s+f[6*i+3]/2}