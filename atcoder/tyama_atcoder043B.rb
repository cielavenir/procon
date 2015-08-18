#!/usr/bin/ruby
M=200000
N=gets.to_i
D=N.times.map{gets.to_i}.sort
A=[0]*(M+1)
As=[0]*(M+1)
B=[0]*(M+1)
D.each{|e|
	A[e/2]+=1
	B[e*2]+=1
}
(M-1).downto(0){|i|A[i]+=A[i+1]}
D.each{|e|As[e]+=A[e]}
(M-1).downto(0){|i|As[i]+=As[i+1]} 
1.upto(M){|i|B[i]+=B[i-1]}
r=0
D.each{|x|r=(r+B[x]*As[2*x])%1000000007}
p r