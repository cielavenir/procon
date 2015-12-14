#!/usr/bin/ruby
M=1000000007;H,W=gets.split.map &:to_i;d=H.gcd(W)
I=[r=0,c=1];F=[1,1]
2.upto(d){|i|I[i]=M-(M/i)*I[M%i]%M;F[i]=F[i-1]*I[i]%M;c=c*i%M}
r=0;(d+1).times{|i|r=(r+c*F[i]*F[d-i])%M if (W/W.gcd(i)).lcm(H/H.gcd(d-i))==H*W/d};p r