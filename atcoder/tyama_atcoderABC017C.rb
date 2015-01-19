#!/usr/bin/ruby
N,M=gets.split.map(&:to_i)
m=[0]*(M+2)
sum=0
N.times{
	l,r,s=gets.split.map(&:to_i)
	m[l]+=s
	m[r+1]-=s
	sum+=s
}
mi=M.times.map{|i|m[i+1]+=m[i]}.min
p sum-mi