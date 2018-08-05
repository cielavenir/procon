#!/usr/bin/ruby
require 'set'
def rev(n)
	n.to_s.reverse.to_i
end
def f1(x,y)
	x<y ? [rev(x),y] : [x,rev(y)]
end
def f2(x,y)
	x<y ? [x,y-x] : [x-y,y]
end
def k(x,y)
	x*10000000+y
end
n__,m__=gets.split.map &:to_i
g=Set.new
r=0
(1..n__).each{|n_|(1..m__).each{|m_|
	n=n_
	m=m_
	if g.include?(k(n,m))
		r+=1
		next
	end
	se=Set.new
	se.add(k(n,m))
	while n!=0&&m!=0
		n,m=f1(n,m)
		n,m=f2(n,m)
		break if se.include?(k(n,m))
		se.add(k(n,m))
	end
	if n!=0&&m!=0
		r+=1
		se.each{|e|g.add(e)}
	end
}}
p r
