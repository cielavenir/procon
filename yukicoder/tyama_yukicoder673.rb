#!/usr/bin/ruby
M=10**9+7
b,c,d=gets.split.map &:to_i
p b*(c<2?d:c*~-c.pow(d,M)*(c-1).pow(M-2,M))%M
