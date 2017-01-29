#!/usr/bin/ruby
n,k,*c=`dd`.split.map(&:to_i)
r=c.pop-(c.reduce(:+)-c[k])/2
puts r==0 ? 'Bon Appetit' : r
