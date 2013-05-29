#!/usr/bin/ruby
a=[1,1]
2.step(45){|i|a<<a[i-1]+a[i-2]}
puts a