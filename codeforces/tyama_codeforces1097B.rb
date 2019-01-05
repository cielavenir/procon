#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
s=a.reduce :+
puts (1<<n).times.any?{|i|t=n.times.select{|j|i[j]>0}.map{|j|a[j]}.reduce 0,:+;(s-2*t)%360==0} ? :YES : :NO
