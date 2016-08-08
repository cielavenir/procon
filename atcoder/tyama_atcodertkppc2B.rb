#!/usr/bin/ruby
N,M=gets.split.map &:to_i
A=$<.map{|e|e.split.map &:to_i}
B=[0]*(M+1)
A.map{|v,t|M.downto(t){|i|B[i]=[B[i],B[i-t]+v].max}}
p B.max