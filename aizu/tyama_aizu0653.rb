#!/usr/bin/ruby
M=2019
A=[false]*-~M
gets
a=gets.split.map &:to_i
a.each{|e|
	A[e]=true
}
gets
gets.split.map(&:to_i).each{|i|
	i-=1
	if a[i]+1<=M && !A[a[i]+1]
		A[a[i]]=false
		a[i]+=1
		A[a[i]]=true
	end
}
p *a
