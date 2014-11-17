#!/usr/bin/ruby
K=gets.to_i
a=[0.0]*(K+6)
(K-1).downto(0){|i|
	a[i]=a[i+1]/6+a[i+2]/6+a[i+3]/6+a[i+4]/6+a[i+5]/6+a[i+6]/6+1
}
p a[0]