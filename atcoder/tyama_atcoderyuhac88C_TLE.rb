#!/usr/bin/ruby
N=gets.to_i
A=N.times.map{gets.chomp}
B=N.times.map{_=gets.split;[A.index(_[0]),_[3]=='good' ? 0 : 1]}
r=[]
(1<<N).times.map{|i|
	c=[]
	if N.times.all?{|j|
		c<<A[j] if i[j]==0
		i[j]^B[j][1]==i[B[j][0]]
	}
		r=['ZZZ']*c.size if c.size>r.size
		r=[c,r].min if c.size==r.size
	end
}
puts r.empty? ? 'No answers' : r.sort