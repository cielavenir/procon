#!/usr/bin/ruby
h,w,a,b=gets.split.map &:to_i;r=0
M=10**9+7;I=[1,1];*F=I;*R=I
2.upto(h+w){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;R<<z*R[-1]%M}
(b...w).each{|i|r=(r+F[h-a-1+i]*R[h-a-1]*R[i]*F[a-1+w-1-i]*R[a-1]*R[w-1-i])%M}
p r