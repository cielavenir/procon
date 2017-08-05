#!/usr/bin/ruby
require'prime';P=Prime.each(10000).to_a
def f(n)
	P.each{|i|
		break if n<i**3
		n/=i**3 while n%i**3==0
	}
	n
end
gets;h=Hash.new 0;$<.map{|e|h[f(e.to_i)]+=1};p h.values.max
