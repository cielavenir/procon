#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
h=Hash.new 0
a.each{|e|h[e]+=1}
r=[h[1],h[2]].min
p r+(h[1]-r)/3
