#!/usr/bin/ruby
M=10**9+7;I=[1,1];*F=I;*R=I;N,K,P,*V=`dd`.split.map &:to_i;V.sort!
2.upto([N+K,100].max){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;R<<z*R[-1]%M}
Q=(100-P)*I[100]%M
P=P*I[100]%M
r=s=0
N.times{|i|r=(r+P.pow(K,M)*Q.pow(i,M)*F[K+i-1]*R[i]*R[K-1]*s)%M;s=(s+V[N-i-1])%M}
K.times{|i|r=(r+P.pow(i,M)*Q.pow(N,M)*F[N+i-1]*R[i]*R[N-1]*s)%M}
p r
