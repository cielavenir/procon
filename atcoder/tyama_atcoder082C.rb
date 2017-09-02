#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
h=Hash.new 0
a.each{|e|h[e]+=1}
p h.each_key.map{|e|h[e-1]+h[e]+h[e+1]}.max
