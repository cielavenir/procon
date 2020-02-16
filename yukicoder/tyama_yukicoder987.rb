#!/usr/bin/ruby
a=`dd`.split
n,m=a.shift(2).map(&:to_i)
op=a.shift
b=a.shift(m).map(&:to_i)
a=a.map(&:to_i)
n.times{|i|puts b.map{|e|a[i].send(op,e)}*' '}
