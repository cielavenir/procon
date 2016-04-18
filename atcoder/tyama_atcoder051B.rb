#!/usr/bin/ruby
a,b=0,1
gets.to_i.times{a,b=b,a+b}
print a,' ',b,$/