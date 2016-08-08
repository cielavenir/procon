#!/usr/bin/ruby
N,K,*A=`dd`.split.map &:to_i
c=K;x=l=0
N.times{|r|
	c-=1 if A[r]==0
	while c<0
		c+=1 if A[l]==0
		l+=1
	end
	x=[x,r-l+1].max
}
p x