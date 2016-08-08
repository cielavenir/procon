#!/usr/bin/ruby
_,w,k=gets.split.map &:to_i
g=w.gcd k
w/=g
k/=g
p w/2*(k/2)+~-w/2*(~-k/2)