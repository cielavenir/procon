#!/usr/bin/env crystal
n,m,l,x=gets.not_nil!.split.map &.to_i
a=gets.not_nil!.split.map &.to_i
q=[1]+[Float64::INFINITY]*(m-1)
n.times{|i|
	q0=q.dup
	m.times{|j|
		t=j+a[i]
		#dp[i+1][t%m]=min(dp[i][t%m],dp[i][j]+floor(t/m)) の間違いでは？
		q0[t%m]=[q[t%m],q[j]+t/m].min
	}
	q=q0
}
puts q[l]>x ? :No : :Yes
