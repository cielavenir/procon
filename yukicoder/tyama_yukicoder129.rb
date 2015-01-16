#!/usr/bin/ruby
k=gets.to_i/1000%n=gets.to_i
r=1
1.step(k){|i|r=r*(n-i+1)/i}
p r%10**9