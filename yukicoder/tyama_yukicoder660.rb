#!/usr/bin/ruby
N=gets.to_i
M=10**9+7;I=[1,1];*F=I;*R=I
2.upto(N*3){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;R<<z*R[-1]%M}
C=->n,a,b,c,f=1{(n+F[a]*R[b]*R[c]*f)%M}
r=C[c=0,N+2*Z=N/2,N+Z,Z]
(Z-1).downto(0){|j|k=Z-j;r=C[r,N+2*j,N+j,j,1-2*c=C[c,2*k-2,k,k-1]]}
p r
