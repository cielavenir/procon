#!/usr/bin/ruby
a=[0,1]
2.step(99){|i|a<<a[i-1]+a[i-2]}
p a[gets.to_i]