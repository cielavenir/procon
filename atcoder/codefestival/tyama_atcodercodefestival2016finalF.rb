#!/usr/bin/ruby
K=10**9+7
N,M=gets.split.map &:to_i
A=(M+1).times.map{(N+2).times.map{[0]*(N+2)}}
A[0][1][1]=1
M.times{|i|(N+1).times{|j|(N+1).times{|k|
	A[i+1][j+1][k]=(A[i+1][j+1][k]+A[i][j][k]*(N-j))%K
	A[i+1][j][k]=(A[i+1][j][k]+A[i][j][k]*(j-k))%K
	A[i+1][j][j]=(A[i+1][j][j]+A[i][j][k]*k)%K
}}}
p A[M][N][N]
