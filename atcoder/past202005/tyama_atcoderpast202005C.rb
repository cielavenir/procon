#!/usr/bin/ruby
a,r,n=gets.split.map &:to_i
r==1&&(p a;exit)
(n-1).times{a*=r;a>10**9&&(puts :large;exit)}
p a
