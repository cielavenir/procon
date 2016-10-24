#!/usr/bin/env crystal
n,m=gets.not_nil!.split.map &.to_i
c=Array.new(n+1){[0]*-~n}
d=c.map &.dup
s=ARGF.gets_to_end.split
r=0
(m-1).times{|t|
	1.upto(n){|i|1.upto(n){|j|
		c[i][j]=c[i-1][j-1]+(s[i-1][t]==s[j-1][t+1] ?1:0)
		d[i][j]=[d[i-1][j],d[i][j-1]].min+c[i][j]
	}}
	r+=d[n][n]
}
p r
