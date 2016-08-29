#!/usr/bin/ruby
N=gets.to_i
A=gets.split.map(&:to_i)
L=gets.to_i
Q=gets.to_i
M=N.times.map{[0]*17}+[[N]*17]
(N-1).times{|i|M[i][0]=((0...N).bsearch{|j|A[j]>A[i]+L}||N)-1}
M[N-1][0]=N
(N-1).downto(0){|i|
	1.upto(16){|j|M[i][j]=M[M[i][j-1]][j-1]}
}
Q.times{
	x,y=gets.split.map(&:to_i).sort
	x-=1
	y-=1
	s=1
	16.downto(0){|i|
		if M[x][i]<y
			x=M[x][i]
			s+=1<<i
		end
	}
	p s
}