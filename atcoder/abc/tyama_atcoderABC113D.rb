#!/usr/bin/ruby
M=10**9+7
mul=->a,b{r=[];W.times{|y|r<<[];W.times{|x|r[y]<<W.times.reduce(0){|s,i|(s+a[y][i]*b[i][x])%M}}};r}
h,W,K=gets.split.map &:to_i
F=[1,1]
(2..W).map{F<<(F[-1]+F[-2])%M}
m=(1..W).map{[0]*W}
(1...W).map{|i|m[i-1][i]=F[i-1]*F[W-i-1]%M}
W.times{|i|m[i][i]=F[i]*F[W-i-1]%M}
(W-1).times{|i|m[i+1][i]=F[i]*F[W-i-2]%M}
e=(0...W).map{|i|[0]*i+[1]+[0]*(W-1-i)}
(h%2>0&&e=mul[m,e];m=mul[m,m];h/=2)while h>0
p e[K-1][0]
