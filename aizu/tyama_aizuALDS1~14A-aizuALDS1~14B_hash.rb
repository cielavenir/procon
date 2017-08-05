#!/usr/bin/ruby
B=999999937
P=1000000007

def gen_hash(s,hash)
	c=0
	s.size.times{|i|
		c=(c*B+s[i])%P
		hash[i]=c
	}
end
def pow_binary_mod(x,y,mod)
	z=1
	while y>0
		z=z*x%mod if (y&1)>0
		x=x*x%mod
		y>>=1
	end
	z
end

s=gets.chomp.each_byte.to_a
ls=s.size
v=[0]*ls
hsh=[0]*10001
gen_hash(s,v)
#gets.to_i.times{
	q=gets.chomp.each_byte.to_a
	lq=q.size
	gen_hash(q,hsh)
	hash=hsh[lq-1]
	Brev=pow_binary_mod(B,lq,P)
	r=[]
	(lq-1...ls).each{|i|
		if v[i]==((i>=lq ? v[i-lq] : 0)*Brev+hash)%P
			r<<i-lq+1
		end
	}
	puts r
#}
