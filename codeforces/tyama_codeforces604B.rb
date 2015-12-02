#!/usr/bin/ruby
_,n=gets.split.map(&:to_i)
a=gets.split.map(&:to_i).reverse
r=0
n.times.map{|i|r=[r,(a[i]||0)+(a[2*n-1-i]||0)].max}
p r