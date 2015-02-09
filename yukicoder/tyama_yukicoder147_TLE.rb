#!/usr/bin/ruby
require 'matrix'
MOD=1000000007
def pow_binary(unit,x,y,&blk)
	blk=lambda{|e|e} if !block_given?
	z = unit
	while y!=0
		z=blk.(z*x) if y&1!=0
		x=blk.(x*x)
		y>>=1
	end
	z
end

r=1
gets.to_i.times{
	c,d=gets.split.map(&:to_i)
	d%=MOD-1 if d>MOD-1
	fib=pow_binary(Matrix[[1,0],[0,1]],Matrix[[1,1],[1,0]],c-1){|x|Matrix[*x.to_a.map{|e|e.map{|f|f%MOD}}]}
	r=r*pow_binary(1,(fib[0,0]+fib[0,1]+fib[1,0]+fib[1,1])%MOD,d){|x|x%MOD}%MOD
}
p r