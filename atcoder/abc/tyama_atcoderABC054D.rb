#!/usr/bin/ruby
class Integer;def infinite?;false end end
n,ma,mb=gets.split.map(&:to_i)
a,b,c=$<.map{|e|e.split.map(&:to_i)}.transpose
amax=a.max
bmax=b.max
dp=(n+1).times.map{(n*amax+1).times.map{[Float::INFINITY]*(n*bmax+1)}}
dp[0][0][0]=0
n.times{|i|
	0.upto(n*amax){|ca|
		0.upto(n*bmax){|cb|
			next if dp[i][ca][cb].infinite?
			dp[i+1][ca][cb]=[dp[i+1][ca][cb],dp[i][ca][cb]].min
			dp[i+1][ca+a[i]][cb+b[i]]=[dp[i+1][ca+a[i]][cb+b[i]],dp[i][ca][cb]+c[i]].min
		}
	}
}
r=Float::INFINITY
1.upto(n*amax){|ca|
	1.upto(n*bmax){|cb|
		r=[r,dp[n][ca][cb]].min if ca*mb==cb*ma
	}
}
p r.infinite? ? -1 : r
