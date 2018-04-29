#!/usr/bin/ruby
N=gets.to_i
M=10**9+7;I=[1,1];*F=I;*R=I
2.upto(N){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;R<<z*R[-1]%M}
r=F[N]
(-~N/2...N).each{|i|r=(r-F[i-1]*R[2*i-N]*F[i])%M}
p r
