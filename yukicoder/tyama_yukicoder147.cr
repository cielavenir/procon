#!/usr/bin/env crystal
require "big"
MOD=1000000007
def mul(a,b,m)
	r=a.size.times.map{[0_i64]*b[0].size}.to_a
	a.size.times{|y|
		b[0].size.times{|x|
			r[y][x]=b.size.times.reduce(0_i64){|s,i|(s+a[y][i]*b[i][x])%m}
		}
	}
	r
end

r=1_i64
gets.not_nil!.to_i.times{
	c_,d_=gets.not_nil!.split
	c=c_.to_i64
	d=BigInt.new(d_)
	x=[[1_i64,1_i64],[1_i64,0_i64]]
	e=[[1_i64,0_i64],[0_i64,1_i64]]
	c-=1
	d%=MOD-1 if d>MOD-1
	while c>0
		e=mul(e,x,MOD) if c%2>0
		x=mul(x,x,MOD)
		c//=2
	end
	y=(e[0][0]+e[0][1]+e[1][0]+e[1][1])%MOD
	while d>0
		r=r*y%MOD if d%2>0
		y=y*y%MOD
		d//=2
	end
}
puts r
