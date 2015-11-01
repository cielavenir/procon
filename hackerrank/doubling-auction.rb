#!/usr/bin/ruby
gets.to_i.times{
	n=gets.to_i
	n+=n.odd? ? 1 : 2
	n>>=1 while (n&1)==0
	p n
}