#!/usr/bin/ruby
K,N=gets.split.map &:to_i;M=998244353;I=[1,1];*F=I;*R=I
2.upto(N+K){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;R<<z*R[-1]%M}
a=[]
1.upto((K+1)/2){|q|i=q*2+1;[x=0,i-K].max.upto([q,N].min){|t|x=(x+F[q]*R[t]*R[q-t]*F[N+K-i]*R[K-i+t]*R[N-t]*2**t)%M};a<<x}
p *[*o=(1...K).map{|i|a[~-i/2]},a[-1],*o.reverse]
