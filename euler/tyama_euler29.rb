#!/usr/bin/ruby
n=gets.to_i
h={}
2.step(n){|a0|
	a=a0*a0
	2.step(n){|b|
		h[a]=1
		a*=a0
	}
}
p h.size
__END__
100