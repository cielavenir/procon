#!/usr/bin/ruby
M,*a=10**9+7;*I=r=j=x=1;n,*z=`dd`.split.map &:to_i
(0..n).map{|i|a[k=z[i]]&&x=a[k]+n-i;a[k]=i}
(0..n).map{|i|p ((r=r*(n+1-i)*I[i]%M)-j)%M;j=j*(x-i)*I[i]%M;I<<(M-M/(i+2))*I[M%(i+2)-1]%M}
