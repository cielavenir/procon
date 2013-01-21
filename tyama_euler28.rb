#!/usr/bin/ruby
p 1+3.step(1001,2).map{|n|4*n**2-6*(n-1)}.reduce(:+)