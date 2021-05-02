#!/usr/bin/ruby
N,Q=gets.split.map &:to_i
S=gets
t=[0]*-~N
N.times{|i|t[i+1]=t[i]+(S[i,2]=='AC' ? 1 : 0)}
Q.times{l,r=gets.split.map &:to_i;p t[r-1]-t[l-1]}
