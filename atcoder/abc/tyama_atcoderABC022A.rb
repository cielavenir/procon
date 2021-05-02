#!/usr/bin/ruby
N,S,T=gets.split.map(&:to_i)
n=r=0
N.times{
	n+=gets.to_i
	r+=1 if S<=n&&n<=T
}
p r