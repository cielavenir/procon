#!/usr/bin/ruby
Z=10**9+7
M=->a,b{(0..3).map{|i|(a[i&~1]*b[i%2]+a[i&~1|1]*b[i%2|2])%Z}}
a=[1,1,1,0]
e=[1,0,0,1]
n=gets.to_i
(n%2>0&&e=M[a,e];a=M[a,a];n/=2)while n>0
p e[0]*e[1]%Z
