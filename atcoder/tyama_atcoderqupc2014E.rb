#!/usr/bin/ruby
X,Y,x,y,h=gets.split.map(&:to_f)
a=x**2+y**2-h**2
b=2*X*x+2*Y*y
c=X**2+Y**2
if a<0
	a=-a
	b=-b
	c=-c
end
begin
	d=Math.sqrt(b**2-4*a*c)
	t = a==0 ? -c/b : -b>=d ? (-b-d)/2/a : (-b+d)/2/a
	puts t<0 ? 'IMPOSSIBLE' : t
rescue Math::DomainError
	puts 'IMPOSSIBLE'
end