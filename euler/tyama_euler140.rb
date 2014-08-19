#!/usr/bin/ruby
p Enumerator.new{|y|
	a=[7,8,13,17,32,43]
	n=[1,2,5,7,14,19]
	y<<2;y<<5
	loop{
		a<<9*a.first+20*n.first
		n<<4*a.first+9*n.first
		y<<(a.last-7)/5 if (a.last-7)%5==0
		a.shift
		n.shift
	}
}.take(30).reduce(:+)