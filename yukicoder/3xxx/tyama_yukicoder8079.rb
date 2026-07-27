#!/usr/bin/ruby
require'prime'
a=[0]
1.upto(10**5){|i|a<<a[-1]+(i.prime? ? 1 : 0)}
gets.to_i.times{p a[gets.to_i]}
