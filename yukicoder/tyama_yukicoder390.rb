#!/usr/bin/ruby
M=1000001
A=[0]*M
gets
gets.split.each{|e|A[e.to_i]=1}
r=0
(1...M).each{|i|
	if A[i]>0
		(i*2).step(M-1,i){|j|
			A[j]=[A[j],A[i]+1].max if A[j]>0
		}
		r=[r,A[i]].max
	end
}
p r