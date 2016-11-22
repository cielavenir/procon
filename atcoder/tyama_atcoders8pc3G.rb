#!/usr/bin/ruby
M=998244353
def m(a,b)
	[(a[0]*b[0]+a[1]*b[2])%M,(a[0]*b[1]+a[1]*b[3])%M,(a[2]*b[0]+a[3]*b[2])%M,(a[2]*b[1]+a[3]*b[3])%M]
end
def f(n)
	e=[1,0,0,1]
	z=[1,1,1,0]
	while n>0
		e=m(e,z) if n%2>0
		z=m(z,z)
		n/=2
	end
	e[1]
end
n,m=gets.split.map &:to_i
I=1,1
2.upto(n){|i|I<<(M-M/i)*I[M%i]%M}
r=f(m+2*n-2)
c=1
0.upto(n-2){|i|
	r=(r+c*(M-f(2*n-2-2*i)))%M
	c=c*(m+i)*I[i+1]%M
}
p r
