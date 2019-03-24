#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;s=0
M=10**9+7;I=[1,1];*F=I;*R=I
2.upto(n){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;R<<z*R[-1]%M}
n.times{|i|s=s+a[i]*F[n-1]*R[i]*R[n-1-i]}
p s%M
