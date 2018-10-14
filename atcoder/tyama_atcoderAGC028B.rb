#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
M=10**9+7;I=[1,1];*F=I;*T=0,1
2.upto(n){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;T<<(T[-1]+z)%M}
r=0
n.times{|i|r=(r+a[i]*(T[i+1]+T[n-i]-1))%M}
p r*F[n]%M
