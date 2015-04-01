#!/usr/bin/ruby
gets.to_i.times{
	a,b,c=gets.split.map(&:to_i)
	if a<b
		p 0
	else
		b=a-b if a<b*2
		r=1
		b.times{|i|
			r=r*(a-i)/(i+1)
		}
		p (r+1)%c #r%c
	end
}