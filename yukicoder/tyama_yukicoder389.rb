#!/usr/bin/ruby
m,*a=`dd`.split.map &:to_i;x=m+1-s=a.reduce(:+);y=a.size;M=10**9+7;I=[1,1];*F=I;*R=I
2.upto(x){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;R<<z*R[-1]%M}
puts s<1?1:x-y<0?:NA:F[x]*R[x-y]*R[y]%M