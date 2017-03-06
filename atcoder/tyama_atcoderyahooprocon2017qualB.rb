#!/usr/bin/ruby
n,k,*a=`dd`.split.map(&:to_i)
p a.sort[0,k].reduce(:+)+k*(k-1)/2
