#!/usr/bin/ruby
M=10**9+7
c=[r=0]*5000
N=gets.to_i
$<.map{|e|c[e.to_i]+=1}
a=[1]+[0]*N
f=a.dup
N.times{|i|f[i+1]=f[i]*-~i%M
N.downto(1){|j|a[j]=(a[j]+a[j-1]*c[i])%M}}
0.upto(N){|i|r=(r+(-1)**(i%2)*a[i]*f[N-i])%M}
p r