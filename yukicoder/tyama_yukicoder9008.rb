#!/usr/bin/ruby
n,*a=`dd`.split.map(&:to_i)
p a.reduce(:+)
