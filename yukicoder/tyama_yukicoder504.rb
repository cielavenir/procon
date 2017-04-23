#!/usr/bin/ruby
n,x,*a=$<.map &:to_i
p q=1
a.each{|e|
	q+=1 if e>x
	p q
}
