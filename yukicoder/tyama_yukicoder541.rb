#!/usr/bin/ruby
M=10**9+7
def mul(a,b)
	r=a.size.times.map{[0]*b[0].size}
	a.size.times{|y|
		b[0].size.times{|x|
			r[y][x]=b.size.times.reduce(0){|s,i|(s+a[y][i]*b[i][x])%M}
		}
	}
	r
end
q=[0,6,40,213,1049,5034,23984]
k=gets.to_i
if k<6
	p q[k]
	exit
end
k-=6
a=[
	[9,-27,38,-29,11,1,-2],
	[1,0,0,0,0,0,0],
	[0,1,0,0,0,0,0],
	[0,0,1,0,0,0,0],
	[0,0,0,1,0,0,0],
	[0,0,0,0,1,0,0],
	[0,0,0,0,0,1,0],
]
e=7.times.map{|i|[0]*i+[1]+[0]*(7-i-1)}
while k>0
	e=mul(e,a) if k%2>0
	a=mul(a,a)
	k/=2
end
p mul(e,[q.reverse].transpose)[0][0]
