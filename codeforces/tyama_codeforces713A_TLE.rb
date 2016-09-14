#!/usr/bin/ruby
h=Hash.new(0)
gets.to_i.times{
	r=0
	x,y=gets.split
	y.each_char{|c|r=r*2+c.to_i%2}
	if x=='+'
		h[r]+=1
	elsif x=='-'
		h[r]-=1
	else
		p h[r]
	end
}