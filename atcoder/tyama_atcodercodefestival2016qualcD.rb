#!/usr/bin/ruby
N,M=gets.split.map &:to_i
C=(N+1).times.map{[0]*-~N}
D=C.map &:dup
S=*$<
r=0
(M-1).times{|t|
	1.upto(N){|i|1.upto(N){|j|
		C[i][j]=C[i-1][j-1]+(S[i-1][t]==S[j-1][t+1]?1:0)
		D[i][j]=[D[i-1][j],D[i][j-1]].min+C[i][j]
	}}
	r+=D[N][N]
}
p r
