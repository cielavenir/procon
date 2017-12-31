#!/usr/bin/env ruby
n,k,*a=`dd`.split.map &:to_i
bag=[0]+[-Float::INFINITY]*k
a.each{|e|k.downto(e){|i|bag[i]=[bag[i],bag[i-e]+e].max}}
p bag.max
