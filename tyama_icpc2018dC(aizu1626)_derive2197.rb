#!/usr/bin/ruby
while s=gets
	n=s.to_i
	break if n==0
	a=n;b=1
	r=0
	(2..1/0.0).each{|i|
		x=n-i*(i-1)/2
		break if x<i
		if x%i==0
			a=x/i
			b=i
		end
	}
	puts '%d %d'%[a,b]
end
