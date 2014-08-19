#!/usr/bin/ruby
m,n=gets.split.map(&:to_i)
p 1.0.step(m).reduce(0){|s,k|s+k*((k/m)**n-((k-1)/m)**n)}