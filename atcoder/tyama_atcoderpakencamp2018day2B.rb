#!/usr/bin/ruby
n,d,*a=`dd`.split.map &:to_i
p a.sort.reverse.each_slice(d).map{|e|e.size<d ? 0 : e.min}.reduce :+
