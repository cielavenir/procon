#!/usr/bin/ruby
def mul(a,b,m)
	r=a.size.times.map{[0]*b[0].size}
	a.size.times{|y|
		b[0].size.times{|x|
			r[y][x]=b.size.times.reduce(0){|s,i|(s+a[y][i]*b[i][x])%m}
		}
	}
	r
end
def fib(k,m)
	x=[[1,1],[1,0]]
	e=[[1,0],[0,1]]
	while k>0
		e=mul(e,x,m) if k%2>0
		x=mul(x,x,m)
		k/=2
	end
	e[0][1]
end
while gets
	p fib(fib($_.to_i,2*10**9+16),10**9+7)
end
