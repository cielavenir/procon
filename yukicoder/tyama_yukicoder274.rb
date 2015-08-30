#!/usr/bin/ruby
N,M=gets.split.map(&:to_i)
A=[0]*(M+1)
N.times{l,r=gets.split.map(&:to_i);A[l]+=1;A[r+1]-=1;A[M-1-r]+=1;A[M-l]-=1}
M.times{|i|A[i+1]+=A[i]}
p A
puts M.times.all?{|i|A[i]<3}?:YES: :NO