#!/usr/bin/env crystal
M=10**9+7
t,a,b,c,d,e=ARGF.gets_to_end.split.map(&.to_i)
w=[a.abs,b.abs,c.abs].max
r=0_i64
x=[1_i64]+[r]*200001
t.times{|i|
	y=[r]*200002
	(-w*-~i..w*-~i).map{|j|
		y[j]=(x[j-a]+x[j+a]+x[j-b]+x[j+b]+x[j-c]+x[j+c])%M
	}
	x=y
}
(d..e).map{|i|r=(r+x[i])%M}
p r
