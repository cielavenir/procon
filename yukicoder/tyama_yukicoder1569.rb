#!/usr/bin/ruby
n,k,*a=`dd`.split.map &:to_i
a<<a.reduce(:^)
p a[~-k%-~n]
