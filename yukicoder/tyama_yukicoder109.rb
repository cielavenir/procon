#!/usr/bin/ruby
gets;$<.map{|e|	
	n,m=e.split.map &:to_i
	a=0
	if (2..Math.sqrt(m)).each{|b|
		(n.downto(a=1){|n|a=a*n%m}if n<b+m/b;break) if m%b<1
	}&&n<m
		(n+1..m-b=1).each{|n|b=b*n%m};a=1+n=m-2;(a=a*b%m if n%2>0;b=b*b%m;n/=2)while n>0
	end
	p a
}