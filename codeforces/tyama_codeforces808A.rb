#!/usr/bin/ruby
n=gets.to_i
(p 1;exit)if n<10
x=10**Math.log10(n).to_i
p (x-n-1)%x+1
