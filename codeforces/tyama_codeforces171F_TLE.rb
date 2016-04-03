#!/usr/bin/ruby
require 'prime'
def rev(n)
	r=0
	while n>0
		r=r*10+n%10
		n/=10
	end
	r
end
n=gets.to_i
Prime.each{|e|
	s=rev(e)
	if s!=e && s.prime?
		n-=1
		if n==0
			p e
			exit
		end
	end
}