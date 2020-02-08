#!/usr/bin/env crystal
K=1000000007
n,m=gets.not_nil!.split.map &.to_i
a=Array.new(m+1){Array.new(n+2){[0_i64]*(n+2)}}
a[0][1][1]=1_i64
m.times{|i|(n+1).times{|j|(n+1).times{|k|
	a[i+1][j+1][k]=(a[i+1][j+1][k]+a[i][j][k]*(n-j))%K
	a[i+1][j][k]=(a[i+1][j][k]+a[i][j][k]*(j-k))%K
	a[i+1][j][j]=(a[i+1][j][j]+a[i][j][k]*k)%K
}}}
p a[m][n][n]
