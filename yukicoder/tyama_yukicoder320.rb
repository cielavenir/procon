#!/usr/bin/ruby
N,M=gets.split.map &:to_i
f=[0,1]
(2..N).each{|i|f[i]=f[i-1]+f[i-2]}
t=f[N]-M
r=0
(N-2).downto(1){|i|(t-=f[i];r+=1)if t>=f[i]}
p t==0?r:-1