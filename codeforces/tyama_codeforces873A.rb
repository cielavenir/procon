#!/usr/bin/ruby
n,k,x,*a=$<.read.split.map &:to_i
k=n if k>n
p a[0...-k].reduce(0,:+)+k*x
