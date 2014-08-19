#!/usr/bin/ruby
require 'rational'
def solve(ma,h)
	m=1
	while m*m<=ma
		n=1
		while n<m
			if n.gcd(m)==1
				a=2*m*n
				b=m*m-n*n
				c=m*m+n*n
				d=1
				while d*(a+b+c)<=ma
					if h[d*(a+b+c)]<a*b*c*d**3
						h[d*(a+b+c)]=a*b*c*d**3
					end
					d+=1
				end
			end
			n+=1
		end
		m+=1
	end
end
h=Hash.new(-1)
solve(3000,h)
gets.to_i.times{
	p h[gets.to_i]
}
__END__
1
1000