#!/usr/bin/ruby
N=gets.to_i+1
A,B=$<.map{|e|e.split.map &:to_i}.transpose.map{|e|(e<<0).sort}
r=0;N.times{|i|r+=[0,A[N-i-1]-B[i]].max*2};p r
