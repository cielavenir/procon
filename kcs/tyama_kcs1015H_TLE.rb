#!/usr/bin/ruby
require 'rational'
MOD=1000000007
fib=Enumerator.new{|y|
	a=1
	b=1
	y<<a
	loop{
		y<<b
		a,b=b,(a+b)%MOD
	}
}
sum=Enumerator.new{|y|
	s=0
	y<<s
	loop{
		s=(s+fib.next)%MOD
		y<<s
	}
}
a=sum.take(5*10**5+1)
gets.to_i.times{
	l,r=gets.split.map(&:to_i)
	val=a[r]-a[l-1]
	val+=MOD if val<0
	p val
}