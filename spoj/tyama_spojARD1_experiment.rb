#!/usr/bin/ruby
=begin
Enumerator.new{|yielder|
	a=-1
	b=1
	c=5
	d=3
	yielder<<[a,b,c,d]
	d+=c
	yielder<<[a,b,c,d]
	c+=a
	d+=c
	yielder<<[a,b,c,d]
	loop{
		c+=b
		d+=c
		a,b=b,a+b
		yielder<<[a,b,c,d]
	}
}.take(20).each{|e|
	p e
}
=end

Enumerator.new{|yielder|
	a=0
	b=1
	yielder<<a
	loop{
		yielder<<b
		a,b=b,a+b
	}
}.take(20).each_with_index{|e,i|
	p e+i*4+3
}