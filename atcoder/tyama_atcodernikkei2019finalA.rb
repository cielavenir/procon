#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
b=[0]
a.each{|e|b<<b[-1]+e}
(1..n).each{|i|p (i..n).map{|j|b[j]-b[j-i]}.max}
