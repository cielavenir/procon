#!/usr/bin/ruby
_,k,*a=`dd`.split.map &:to_i
p (a.reduce(:+)+k-1)/k
