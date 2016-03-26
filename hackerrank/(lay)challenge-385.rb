#!/usr/bin/ruby
D=10
gets.to_i.times{
	n=gets.to_i
	r=0
	if n>=100
		r+=(n-(100-D))/D
		n-=r*D
	end
	r+=1
	x=p=1
	while n>0
		r+=(p*=n.to_f/100)*(1-(n=[n-D,0].max).to_f/100)*x
		x+=1
	end
	p r
}