#!/usr/bin/ruby
def dfs(row,col,n,k)
	return if n==0
	k.times{|i|A[row+i][col+i,2*k-2*i-1]='_'*(2*k-2*i-1)}
	dfs(row+k/2,col-k/2,n-1,k/2)
	dfs(row+k/2,col+3*k/2,n-1,k/2)
	dfs(row-k/2,col+k/2,n-1,k/2)
end

A=32.times.map{|i|'_'*(31-i)+'1'*(2*i+1)+'_'*(31-i)}
N=gets.to_i
dfs(16,16,N,16)
puts A