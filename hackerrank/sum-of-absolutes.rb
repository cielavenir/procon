#!/usr/bin/ruby
N,Q=gets.split.map(&:to_i)
A=[0]+gets.split.map(&:to_i)
1.step(N){|i|A[i]+=A[i-1]}
Q.times{
	a,b=gets.split.map(&:to_i)
	puts [:Even,:Odd][(A[b]-A[a-1])%2]
}