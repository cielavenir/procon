#!/usr/bin/ruby
N=100000
L=gets.to_i
M=gets.split.map(&:to_i)
R=gets.split.map(&:to_i)
r=0
N.times{|i|
	r+=1 if L.times.any?{|j|i%M[j]==R[j]}
}
p r.to_f/N