#!/usr/bin/env crystal
lib C;fun strtoll(s: UInt8*,p: UInt8**,b: Int32): Int64;end
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
n=C.strtoll(gets.not_nil!,nil,10)
puts pow(n)*pow(n+1)%M
