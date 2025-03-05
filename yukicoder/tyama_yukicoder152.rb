#!/usr/bin/ruby
L=gets.to_i/4
r=0
(2..Math.sqrt(L)).each{|m|(1-m%2).step(m-1,2){|n|next if m.gcd(n)>1
r+=1 if 2*m*(m+n)<=L}}
p r
