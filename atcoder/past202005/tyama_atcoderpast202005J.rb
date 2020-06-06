#!/usr/bin/ruby
N,M,*A=`dd`.split.map &:to_i
X=[0]*N
A.each{|e|
	idx=((0...N).bsearch{|i|X[i]<e}||-2)+1
	idx>0 && X[idx-1]=e
	p idx
}
