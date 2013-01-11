#!/usr/bin/ruby
a=[1]
1.step(50){|i|a<<a[[0,i-4].max..i].reduce(:+)}
p a.last