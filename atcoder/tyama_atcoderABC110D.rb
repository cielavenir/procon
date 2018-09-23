#!/usr/bin/ruby
require'prime'
N,M=gets.split.map &:to_i
r=1
M.prime_division.map{|n,k|k.times{|i|r=r*(N+k+~i)/-~i}}
p r%(10**9+7)
