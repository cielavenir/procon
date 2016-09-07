#!/usr/bin/ruby
n,m=gets.split.map &:to_i
M=10**9+7
A=[j=0]*-~n
B=[0]*-~m
s=1
n.times{|i|j=[j,B[x=gets.to_i]].max;B[x]=i+1;s=((A[i+1]=(A[i]+s)%M)-A[j])%M}
p s