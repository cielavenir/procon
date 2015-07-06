#!/usr/bin/ruby
h={}
(0..5).each{|n|[3,5,17,257,65537].combination(n){|a|(0..29).each{|i|h[2**i*a.reduce(1,:*)]=1}}}
A=h.keys.sort
N=gets.to_i
p (0..A.size).bsearch{|i|A[i]>N}-2

#32.times{|n|(0..29).each{|i|h[2**i*(0..4).reduce(1){|s,i|s*[1,[3,5,17,257,65537][i]][n[i]]}]=1}}