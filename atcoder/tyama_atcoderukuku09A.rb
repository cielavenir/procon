#!/usr/bin/ruby
gets.to_i.times{
	x=gets.to_i
	a=b=1
	r=0
	while x>a
		r=(x-a)/b if (x-a)%b==0
		a,b=b,a+b
	end
	puts '1 %d'%r
}
