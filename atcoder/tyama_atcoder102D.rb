#!/usr/bin/ruby
l=gets.to_i
n=l.bit_length
a=[];b=1
(n-1).times{|i|*q=n+~i,n-i;a<<q+[1<<i]<<q+[0];b&l>0&&a<<[1,n-i,l^=b];b*=2}
[[n,a.size],*a].map{|e|puts e*' '}
