#!/usr/bin/ruby
require'matrix';f=->(n){(Matrix[[1,1],[1,0]]**n)[1,0]};puts (n=gets.to_i)==2?[3,:INF]:[n,f[n]-(n%2>0?0:f[n/2]**2)]