#!/usr/bin/ruby
s,n=gets.split.map &:to_i;s-=n;p s<0?0:(b=[1]+[0]*s;1.upto(n){|i|i.upto(s){|j|b[j]=(b[j-i]+b[j])%(10**9+7)}};b[s])
