#!/usr/bin/ruby
T=Hash.new(0)
T[0]=100000
T[1]=50000
T[2]=30000
T[3]=20000
T[4]=10000
N=gets.to_i
A=[nil]*N
N.times.map{|i|
	n=gets.to_i
	A[n-1]=i
}
puts A.map{|e|T[e]}