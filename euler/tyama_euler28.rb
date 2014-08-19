#!/usr/bin/ruby
gets.to_i.times{
	#an=4*n**2-6*n-6
	#bn=a(2*n+1)=16*n**2+4*n+4
	n=gets.to_i/2
	#sigma(k=1->n){16*k**2+4*k+4) = (16*n**3+30*n**2+26*n)/3
	#(also valid for n=0)
	p (1+(16*n**3+30*n**2+26*n)/3) % 1000000007
}
__END__
1
1001