#!/usr/bin/ruby
N,K=$<.map &:to_i
s=0.0
(t=7**7).times{a=0
N.times{|i|a+=rand(1..6);a-=rand((i<K ? 4:1)..6)}
s+=1 if a<0}
p s/t