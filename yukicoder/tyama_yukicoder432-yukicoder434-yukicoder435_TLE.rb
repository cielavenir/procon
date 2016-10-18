#!/usr/bin/ruby
I=[nil,1,5,nil,7,2,nil,4,8]
def z(n)
	r=0
	while n%3==0
		r+=1
		n/=3
	end
	[n,r]
end
def comb(n,k)
	k0,z0=F[n]
	k1,z1=F[k]
	k2,z2=F[n-k]
	z=z0-z1-z2
	r=k0*I[k1]*I[k2]%9
	#[r,r*3%9][z]||0
	r*3**z%9
end

F=[[1,0]]
(1..100000).each{|i|
	k0,z0=F[i-1]
	k1,z1=z(i)
	F[i]=[k0*k1%9,z0+z1]
}
gets.to_i.times{
	r=0
	f=true
if false
	n,x,a,b,m=gets.split.map(&:to_i)
	n.times{|i|
		c=x%10
		r=(r+c*comb(n-1,i))%9
		f=false if c!=0
		x=((x^a)+b)%m
	}
else
	s=gets.chomp
	n=s.size
	s.each_byte.with_index{|b,i|
		r=(r+(b-48)*comb(n-1,i))%9
		f=false if b!=48
	}
end
	p r!=0||f ? r : 9
}
