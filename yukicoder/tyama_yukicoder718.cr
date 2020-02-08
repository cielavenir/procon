#!/usr/bin/env crystal
M=1000000007
A=[[1_i64,1_i64],[1_i64,0_i64]]
E=[[1_i64,0_i64],[0_i64,1_i64]]
def mul(a,b)
	r=a.size.times.map{[0_i64]*b[0].size}.to_a
	a.size.times{|y|
		b[0].size.times{|x|
			r[y][x]=b.size.times.reduce(0_i64){|s,i|(s+a[y][i]*b[i][x])%M}
		}
	}
	r
end
def pow(n)
	a=A
	e=E
	while n>0
		e=mul(a,e) if n%2>0
		a=mul(a,a)
		n//=2
	end
	e[0][1]
end
n=gets.not_nil!.to_i64
puts pow(n)*pow(n+1)%M
