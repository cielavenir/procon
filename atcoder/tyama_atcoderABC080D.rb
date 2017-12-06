#!/usr/bin/ruby
S=200002
N,C=gets.split.map &:to_i
H=Hash.new{|h,k|h[k]=[]}
N.times{
	s,t,c=gets.split.map &:to_i
	H[c]<<[s,t]
}
A=[0]*S
H.each{|k,v|
	v.sort!
	(v.size-2).downto(0){|i|
		if v[i][1]==v[i+1][0]
			v[i][1]=v[i+1][1]
			v.delete_at(i+1)
		end
	}
	v.each{|a,b|
		A[a*2-1]+=1
		A[b*2]-=1
	}
}
(1...S).each{|i|A[i]+=A[i-1]}
p A.max
