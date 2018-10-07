#!/usr/bin/ruby
A=[]
gets.to_i.times{
	a=gets.split.map &:to_i
	if a[0]==0
		A.send(a[1]==0 ? :unshift : :push,a[2])
	elsif a[0]==1
		p A[a[1]]
	elsif a[1]==0
		A.shift
	else
		A.pop
	end
}
