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
p 2.step(10000).select{|i|z(i).length%2==0}.count