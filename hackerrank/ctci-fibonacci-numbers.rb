#!/usr/bin/ruby
a,b,n=0,1,gets.to_i
(n-1).times{a,b=b,a+b}
p b
