#!/usr/bin/ruby
a=[1,1]
2.step(50){|i|a[i]=a[i-1]+a[i-2]}
p a[gets.to_i]