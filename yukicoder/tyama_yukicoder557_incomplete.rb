#!/usr/bin/ruby
n=gets.to_i
r=[1,3][n%2]
(p 2;exit)if n<2
n/=2
(n-=1;r*=4)if n>0
p r*5**n%(10**9+7)
