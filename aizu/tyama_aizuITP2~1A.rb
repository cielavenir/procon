#!/usr/bin/ruby
A=[]
gets.to_i.times{
	a=gets.split.map &:to_i
	if a[0]==0
		A<<a[1]
	elsif a[0]==1
		p A[a[1]]
	else
		A.pop
	end
}
