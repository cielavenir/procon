#!/usr/bin/ruby
M=10**9+7
def d(x,y) x.zip(y).reduce(0){|s,(a,b)|s+a*b} end
def mul(x,y)
	y=y.transpose
	[[d(x[0],y[0])%M,d(x[0],y[1])%M],[d(x[1],y[0])%M,d(x[1],y[1])%M]]
end
h,w,k=gets.split.map(&:to_i)
k-=1
m=$<.map{|e|e.chomp.chars};mt=m.transpose
c=m.count{|s|s[0]=='#'&&s[-1]=='#'}
d=mt.count{|s|s[0]=='#'&&s[-1]=='#'}
if d>0
	(p 1;exit) if c>0
	c,m,w=d,mt,h
end
a=b=0
m.each{|s|w.times{|i|
	a+=1 if s[i]=='#'
	b+=1 if i<w-1&&s[i]=='#'&&s[i+1]=='#'
}}
b=0 if c==0&&d==0
e=[[1,0],[0,1]]
m=[[a,-b],[0,c]]
while k>0
	e=mul(e,m) if k%2>0
	m=mul(m,m)
	k/=2
end
p (e[0][0]+e[0][1])%M