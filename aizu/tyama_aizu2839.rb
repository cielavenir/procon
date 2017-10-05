#!/usr/bin/ruby
n,m=gets.split.map &:to_i
(p (m+1)%(10**9+7);exit)if n==1
r=(0..m+1).bsearch{|i|m<(n-1)*i}-1
p (-~m*(r*2+1)-~-n*r*-~r)%(10**9+7)
