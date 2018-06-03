#!/usr/bin/ruby
N,A,B,K=gets.split.map &:to_i
M=998244353;I=[1,1];*F=I;*R=I
2.upto(N){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;R<<z*R[-1]%M}
r=0;0.upto(N){|a|
	b=(K-A*a)/B
	0<=b&&b<=N&&A*a+B*b==K&&r=(r+F[N]**2*R[a]*R[N-a]*R[b]*R[N-b])%M
}
p r
