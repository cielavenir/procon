#!/usr/bin/ruby
N,T=gets.split.map &:to_i
s=0
A=N.times.map{a,b=gets.split.map &:to_i;s+=a;b-a}.sort
p s>T ? (1..N).find{|i|(s+=A[i-1])<=T}||-1:0