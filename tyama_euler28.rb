#!/usr/bin/ruby
p 1+3.step(1001,2).reduce(0){|s,n|s+=4*n**2-6*(n-1)}