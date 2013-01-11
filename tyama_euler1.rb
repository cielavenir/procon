#!/usr/bin/ruby
p 1000.times.reduce(0){|s,i|s+=i%3==0||i%5==0?i:0}