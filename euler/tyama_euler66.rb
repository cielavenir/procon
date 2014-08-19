#!/usr/bin/ruby
def z(n)
	a=sqi=Math.sqrt(n).to_i
	r=[sqi]
	if sqi**2==n then return r end
	sqir=0;sf=1
	begin
		sqir=a*sf-sqir
		sf=(n-sqir**2)/sf
		r.push(a=(sqir+sqi)/sf)
	end while sf!=1
	return r
end
def pelleq(n)
	c=z(n)
	l=c.size-1
	per= l%2==0 ? l-1 : 2*l-1
	a=c[0];a1=1;b=1;b1=0
	1.step(per){|i|
		a,a1=c[(i-1)%l+1]*a+a1,a
		b,b1=c[(i-1)%l+1]*b+b1,b
	}
	return a
end
p 2.step(1000).map{|i|[pelleq(i),i]}.max[1]