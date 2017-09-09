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
q=[1,8,38,184,976,5382,29739,163496,896476,4913258,26932712,147657866]
k=gets.to_i
if k<11
	p q[k]
	exit
end
k-=11
e=12.times.map{|i|[0]*i+[1]+[0]*(12-i-1)}
a=[
	[12,-54,124,-133,-16,175,-94,-69,40,12,-4,-1],
	*e[0...-1]
]
while k>0
	e=mul(e,a) if k%2>0
	a=mul(a,a)
	k/=2
end
p mul(e,[q.reverse].transpose)[0][0]
