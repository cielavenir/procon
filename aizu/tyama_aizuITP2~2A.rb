#!/usr/bin/ruby
n,q=gets.split.map &:to_i
A=n.times.map{[]}
q.times{
	a=gets.split.map &:to_i
	if a[0]==0
		A[a[1]]<<a[2]
	elsif a[0]==1
		puts A[a[1]][-1] if A[a[1]][-1]
	else
		A[a[1]].pop
	end
}
