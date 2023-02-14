#!/usr/bin/ruby
D=gets.to_i
M=998244353;I=[1,1];*F=I;*R=I
2.upto(2*D){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;R<<z*R[-1]%M}
p F[2*D]*R[D]*R[D]*R[2]%M
