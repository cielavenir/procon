#!/usr/bin/ruby
K=10**6
a=[0.0]*(K+6)
(K-1).downto(0){|i|
	a[i]=1+a[i+1]/12+a[i+2]/6+a[i+3]/4+a[i+4]/12+a[i+5]/4+a[i+6]/6
}
gets.to_i.times{p a[K-gets.to_i]}