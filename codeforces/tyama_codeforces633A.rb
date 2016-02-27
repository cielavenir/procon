#!/usr/bin/ruby
def egcd(x,y)
    return [x,1,0] if y==0
    g,a,b=egcd(y,x%y)
    [g,b,a-x/y*b]
end
a,b,c=gets.split.map(&:to_i)
g=a.gcd(b)
if c%g!=0
	puts :No
else
	a/=g
	b/=g
	c/=g
	_,z1,z2=egcd(a,b)
	n=[a,b].max+c
	puts (-n..n).find{|i|z1*c+b*i>=0 && z2*c-a*i>=0} ? :Yes : :No
end