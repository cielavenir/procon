#!/usr/bin/ruby
M=10**9+7;F=[1,f=1];C=[0,0];f=1
2.upto(1e6){|i|F<<F[i-1]*i%M;C<<(C[i-1]*i+F[i-1])%M}
T=gets.to_i
(1..T).each{|i|
	n=gets.to_i
	p n*n
	p n*(n*n+~-n)
	p T
	p 4*n*n+17
	p n.pow(n**3,M)
	p n
	p (n*C[n])%M
	puts
}
