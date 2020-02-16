#!/usr/bin/ruby
a=`dd`.split
n,m,k=a.shift(3).map(&:to_i)
op=a.shift
b=a.shift(m).map(&:to_i)
a=a.map(&:to_i)
sa=a.sum
sb=b.sum
p (op=='+' ? m*sa+n*sb : sa*sb)%k
