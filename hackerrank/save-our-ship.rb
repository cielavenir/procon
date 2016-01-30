#!/usr/bin/ruby
S=gets.strip
N=S.size/3
T='SOS'*N
p S.size.times.count{|i|S[i]!=T[i]}