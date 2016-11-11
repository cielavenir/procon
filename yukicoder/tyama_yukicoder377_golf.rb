#!/usr/bin/ruby
require'prime'
def x(a,d=0,n=1,t=1)d==a.size ?yield(n,t):(0..a[d][1]).map{|i|x(a,d+1,n*a[d][0]**i,i>0?t*~-a[d][0]*a[d][0]**~-i:t,&proc)}end
q=->x,y{z=1;(y%2>0&&z=z*x%M;x=x*x%M;y/=2)while y>0;z}
C={}
r=M=10**9+7
H,W,K=gets.split.map &:to_i
Z=:prime_division
x(H.send(Z)){|a,c|x(W.send(Z)){|b,d|r=(r+c*d*C[k=W*H/a.lcm(b)]||=q[K,k])%M}}
p r*q[W*H,M-2]%M
