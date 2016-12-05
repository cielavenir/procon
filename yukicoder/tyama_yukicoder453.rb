#!/usr/bin/ruby
A,B=gets.split.map &:to_f
a,b=20*A-8*B,21*B-7*A
p 1000*(a<0?7*A : b<0?4*B : (a+2*b)/13)
