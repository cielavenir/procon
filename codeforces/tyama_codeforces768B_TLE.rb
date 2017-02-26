#!/usr/bin/ruby
def f(pos,t,n)
	return n if n<2
	return n%2 if pos+1==2*t
	n/=2
	pos/=2
	f(pos,t-(t>pos+1 ? pos+1 : 0),n)
end
n,l,r=gets.split.map &:to_i
x=1
x*=2 while x<=n
x-=1
p (l..r).reduce(0){|s,i|s+f(x,i,n)}
