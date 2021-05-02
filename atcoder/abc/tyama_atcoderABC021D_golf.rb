#!/usr/bin/ruby
require'openssl'
M=10**9+7
n,k=$<.map &:to_i
n+=k-1
r=1
k.times{|i|r=r*(n-i)*(i+1).to_bn.mod_exp(M-2,M)%M}
p r
