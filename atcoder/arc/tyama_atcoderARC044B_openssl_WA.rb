#!/usr/bin/ruby
require'openssl'
N,*A=`dd`.split.map &:to_i
if A[0]>0||A.count(0)>1
	p 0
else
	T=2.to_bn
	C=[0]*N
	A.each{|e|C[e]+=1}
	r=1
	M=1000000007
	1.step(N-1){|i|
		r=r*(T.mod_exp(C[i-1],M)-1).mod_exp(C[i],M)*T.mod_exp(C[i]*(C[i]-1)/2,M)%M
	}
	p r
end
