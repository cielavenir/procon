#!/usr/bin/ruby
require 'rational'
L=gets.to_i/4
r=0
2.step(L){|m|(1-m%2).step(m-1,2){|n|next if m.gcd(n)>1
break if 2*m*(m+n)>L
r+=1}}
p r