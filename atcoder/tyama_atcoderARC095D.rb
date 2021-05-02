#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
a.sort!
m=a.pop
puts '%d %d'%[m,a.min_by{|e|(m-e*2).abs}]
