#!/usr/bin/ruby
a=`dd`.split
n,m,k=a.shift(3).map(&:to_i)
op=a.shift
b=a.shift(m).map(&:to_i)
a=a.map(&:to_i).sort
p b.map{|e|a.size-((0...a.size).bsearch{|i|e.send(op,a[i])>=k}||a.size)}.sum
