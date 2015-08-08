#!/usr/bin/ruby
N,M=gets.split.map(&:to_i)
S=gets.to_i
k0=r=0
A=N.times.map{gets.split.map(&:to_i)}.sort+[[S,0]]
A.each_with_index{|(t,k),i|
	r+=t-A[i-1][0] if k0>=M
	k0+=k
}
p r