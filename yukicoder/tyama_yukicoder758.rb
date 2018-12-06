#!/usr/bin/ruby
M=10**9+7;I=[1,1];*F=I;*R=I;n=gets.to_i-1
2.upto(n){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;R<<z*R[-1]%M}
r=$<.map(&:to_i).uniq.size
p r<1?1:F[n]**2*R[r]*R[n-r]*R[r-1]*R[n-r+1]*I[n]%M
