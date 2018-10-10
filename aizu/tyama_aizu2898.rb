#!/usr/bin/ruby
M=10000003
A=[false]*M
A[0]=A[1]=true
(2...M).each{|i|!A[i]&&(i*2).step(M-1,i){|j|A[j]=true}}
p (3..gets.to_i).count{|i|!A[i]&&!A[i+2]}*2
