#!/usr/bin/ruby
a=[1,1,1,2]
4.step(50){|i|a<<1+a[0..(i-4)].reduce(:+)+a[i-1]}
p a.last