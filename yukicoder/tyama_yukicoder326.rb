#!/usr/bin/ruby
N=gets.to_i
A=[*1..N]
gets.to_i.times{
	a=gets.to_i
	A[a-1],A[a]=A[a],A[a-1]
}
B=[nil]*N
gets.split.each_with_index{|e,i|B[e.to_i-1]=i+1}
R=[]
(N-1).downto(1){|i|
	t=B[i]
	1.upto(i){|j|
		if A[j-1]==t
			R<<[j,j+1]
			A[j-1],A[j]=A[j],A[j-1]
		end
	}
}
p R.size
puts R.map{|e|'%d %d'%e}