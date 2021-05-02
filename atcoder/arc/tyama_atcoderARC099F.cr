#!/usr/bin/env crystal
B=1000000000000000003_i64
P=1000000000000000031_i64
def mul(x,y,m)
	z=0_i64
	while y>0
		(z+=x;z>=m&&(z-=m)) if y%2>0
		x+=x;x>=m&&(x-=m)
		y/=2
	end
	z
end
def pow(x,y,m)
	z=1_i64
	while y>0
		z=mul(z,x,m) if y%2>0
		x=mul(x,x,m)
		y/=2
	end
	z
end
Brev=pow(B,P-2,P)
n=gets.not_nil!.to_i
s=gets.not_nil!.chomp
o=Array(Int64).new(n+1,0_i64)
p=Array(Int64).new(n+1,0_i64)
p[0]=1_i64
1.upto(n){|i|
	p[i]=p[i-1];o[i]=o[i-1]
	if s[i-1]=='>'
		p[i]=mul(p[i],B,P)
	elsif s[i-1]=='<'
		p[i]=mul(p[i],Brev,P)
	elsif s[i-1]=='+'
		o[i]=(o[i]+p[i])%P
	elsif s[i-1]=='-'
		o[i]=(o[i]-p[i]+P)%P
	end
}
m=Hash(Int64,Int32).new(0)
r=0_i64
n.downto(1){|i|
	m[o[i]]+=1
	r+=m[(mul(o[n],p[i-1],P)+o[i-1])%P]
}
puts r
