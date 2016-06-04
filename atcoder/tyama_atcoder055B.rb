#!/usr/bin/ruby
N,K=gets.split.map &:to_i
M=(0..1).map{[0.0]*-~K}
f=->r,s{[1.0/N+M[r][s-1],M[r][s]].max}
(N-1).downto(0){|r|M[r&1][0]=M[r&1^1][0];1.upto(K){|s|M[r&1][s]=M[r&1^1][s]+f[r&1^1,s]/r}}
p f[1,K]