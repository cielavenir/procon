#!/usr/bin/env crystal
M=10**9+7
c=[0]*5000
r=0_i64
n=gets.not_nil!.to_i
n.times{c[gets.not_nil!.to_i]+=1}
a=[1_i64]+[0_i64]*n
f=a.dup
n.times{|i|f[i+1]=f[i]*-~i%M
n.downto(1){|j|a[j]=(a[j]+a[j-1]*c[i])%M}}
0.upto(n){|i|r=(r+a[i]*(-1)**(i%2)*f[n-i])%M}
puts r
