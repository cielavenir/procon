#!/usr/bin/ruby
M=10**9+7
A=[[1,1],[1,0]]
def mul(a,b)
	r=(0...a.size).map{[0]*b[0].size}
	a.size.times{|y|
		b[0].size.times{|x|
			r[y][x]=b.size.times.reduce(0){|s,i|(s+a[y][i]*b[i][x])%M}
		}
	}
	r
end
def pow(a,n)
	e=(0...a.size).map{|i|[0]*i+[1]+[0]*(a.size-1-i)}
	while n>0
		e=mul(a,e) if n%2>0
		a=mul(a,a)
		n/=2
	end
	e[-1][0]
end
n,m=gets.split.map &:to_i
a=pow(A,m+1)
b=pow(A,m)
c=pow(A,m-1)
p pow([[a,b,0],[b,c,0],[0,1,1]],n+1)
