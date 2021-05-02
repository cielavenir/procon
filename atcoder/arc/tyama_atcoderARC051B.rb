#!/usr/bin/ruby
a=b=1
gets.to_i.times{a,b=a+b,a}
p a,b
#print a,' ',b,$/
