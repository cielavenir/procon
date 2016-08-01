#!/usr/bin/ruby
D=lambda{|x|(s=H[x].map{|e|D[e]}).reduce(A[x]+=y=x==0?0:H[x].map{|e|A[e]}.min||0,:+)-y*s.size}
N,M=gets.split.map &:to_i
H=Hash.new{|h,k|h[k]=[]}
A=[0]*N
1.upto(N-1){|i|H[gets.to_i]<<i}
M.times{x,y=gets.split.map &:to_i;A[x]=y}
p D[0]