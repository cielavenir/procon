#!/usr/bin/ruby
D=[[-1,0],[1,0],[0,-1],[0,1]]
def f(i,j,d)
	return 0 if i<0||N<=i || j<0||M<=j || A[i][j]=='B'
	f(i+D[d][0],j+D[d][1],d)+1
end
N,M=gets.split.map(&:to_i)
A=N.times.map{gets.chomp.chars.to_a}
a=N.times.flat_map{|i|M.times.map{|j|4.times.map{|k|f(i,j,k)}.min}}.sort
p (a[-1]*4-3)*(a[-2]*4-3)