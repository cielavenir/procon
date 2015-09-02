#!/usr/bin/ruby
gets.to_i.times{
	p,q,d=gets.split.map(&:to_i)
	x,y=[1,1]
	while ((x+p)/q)<d do x,y=[3*x+4*y,2*x+3*y] end # depends on p,q...
	puts '%d %d'%[(y+p)/q,(x+p)/q]
}
__END__
1
1 2 1000000000000