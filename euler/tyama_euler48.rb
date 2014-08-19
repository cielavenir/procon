#!/usr/bin/ruby
p 1.step(1000).reduce(0){|s,i|s+=i**i}%10**10