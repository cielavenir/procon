#!/usr/bin/ruby
a=b=1
(gets.to_i-1).times{a,b=b,a+b}
p a