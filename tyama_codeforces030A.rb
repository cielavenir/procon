#!/usr/bin/ruby
a,b,n=gets.split.map(&:to_i)
if a==0
	puts b==0 ? 1 : 'No solution'
	exit
end
if a<0 then a=-a;b=-b end
sign=1
if b<0
	sign=-1 if n.odd?
	b=-b
end
r=(b.to_f/a)**(1.0/n)+1e-9
if (r-r.to_i).abs>1e-8 then puts 'No solution';exit end
p r.to_i*sign