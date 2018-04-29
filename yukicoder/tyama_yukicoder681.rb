#!/usr/bin/ruby
M=10**9+7
def C(i,d) ~-(-~d).pow(i) end
def S(i,d) (-~d*~-(-~d).pow(i,M)*d.pow(M-2,M)-i)%M end
n,b,d=`dd`.split.map &:to_i
i=(1..1.0/0).find{|i|C(i,d)>n}
r=S(b,d)
(i-1).downto(0){|i|
	k=C(i,d)
	s,n=n.divmod k+1
	r=(r-s*(S(i,d)-~i))%M
}
p r
