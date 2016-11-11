#!/usr/bin/ruby
def pow(x,y,m)
	z=1
	while y>0
		z=z*x%m if y%2>0
		x=x*x%m
		y/=2
	end
	z
end
M=10**9+7
K=gets.to_i
C=gets.split.map(&:to_i)
s=C.reduce(:+)
g=C.reduce(:gcd)
r=0
x=[]
y=[]
g.downto(1){|i|
	next if g%i!=0
	rem=s/i-1
	m=d=1
	K.times{|j|
		(C[j]/i-(j==0 ? 1 : 0)).times{|l|
			m=m*rem%M
			d=d*(l+1)%M
			rem-=1
		}
	}
	m*=pow(d,M-2,M)
	x.size.times{|j|
		m-=y[j] if x[j]%i==0
	}
	m%=M
	y<<m
	m=m*pow(C[0]/i,M-2,M)%M
	x<<i
	r=(r+m)%M
}
p r
