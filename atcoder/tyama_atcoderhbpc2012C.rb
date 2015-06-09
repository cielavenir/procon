#!/usr/bin/ruby
h={}
gets.to_i.times{
	s=gets.chomp
	a=s.split('.')
	b=a[1].split('(')
	a=[a[0],b[0],(b[1]||'')[0...-1]]
	n=a[0].to_i+Rational(a[1].to_i,10**a[1].size) + (a[2].empty? ? 0 : Rational(a[2].to_i,10**a[1].size*(10**a[2].size-1)))
	h[n]=1
}
p h.size