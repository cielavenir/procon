#!/usr/bin/ruby
M=gets.to_i
S=(1<<M).times.map{gets.to_i}
W=(1<<M).times.map{|x|(1<<M).times.map{|y|S[x]*S[x]*1.0/(S[x]*S[x]+S[y]*S[y])}}
p=(1<<M).times.map{1}
msk=0xffffffff
M.times{|i|
	msk-=1<<i
	pnxt=[]
	(1<<M).times{|x|
		nxt=0
		(1<<M).times{|y|nxt+=p[y]*W[x][y] if (x&msk)==(y&msk) && (x^y)[i]==1}
		pnxt<<p[x]*nxt
	}
	p=pnxt
}
p p[0]