#!/usr/bin/ruby
n,m,*l=`dd`.split.map &:to_i
h=Hash.new 0
l.map{|e|h[e]+=1}
(1..m).each{|i|puts '%d %d'%[i,h[i]]}
