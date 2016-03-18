#!/usr/bin/ruby
require 'prime'
def solve(factor,ma)
	r=0
	(1..factor.size).each{|n|
		factor.combination(n){|a|
			divisor=a.reduce(:*)
			items=ma/divisor
			items_sum=items*(items+1)/2
			r+=(-1)**(~n%2) * items # _sum*divisor
		}
	}
	r
end
gets.to_i.times{
	x,n=gets.split.map(&:to_i)
	p n-solve(x.prime_division.map(&:first),n)
}