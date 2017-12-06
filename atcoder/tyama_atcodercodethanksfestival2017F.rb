#!/usr/bin/ruby
H=Hash.new 0;H[0]=1
N,K=gets.split.map &:to_i
N.times{n=gets.to_i;H.to_a.each{|k,v|H[k^n]=(H[k^n]+v)%(10**9+7)}}
p H[K]
