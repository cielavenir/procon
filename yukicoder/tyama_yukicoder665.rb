#!/usr/bin/ruby
M=10**9+7;F=[1];Q=[r=0];N,K=gets.split.map &:to_i;a=N
P=->a,n=M-2{
if RUBY_VERSION>='2.5'
a.pow(n,M)
else
z=1;(n%2>0&&z=z*a%M;a=a*a%M;n/=2)while n>0;z
end
}
1.upto(K+1){|i|a=a*(N-i)%M;Q<<(P[i,K]+Q[-1])%M;F<<i*F[-1]%M}
p N>K+1?(0.upto(K+1){|i|r=(r+Q[i]*a*P[N-i]*P[F[K+1-i]*F[i]]*[-1,1][(i+K)%2])%M};r):Q[N]
