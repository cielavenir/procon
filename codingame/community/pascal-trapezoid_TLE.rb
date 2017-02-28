#!/usr/bin/ruby
_,l,n=gets.split.map(&:to_i)
a=gets.split
(l-1).times{
	a=[a[0]]+a.each_cons(2).map{|x,y|
		begin
			(Integer(x)+Integer(y)).to_s
		rescue ArgumentError
			x+y
		end
	}+[a[-1]]
}
puts a[n-1]
