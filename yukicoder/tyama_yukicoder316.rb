#!/usr/bin/ruby
#reduce(:*)ではなくreduce(:lcm)を使う以外はCodeIQ q1560を流用
def solve(factor,ma)
	r=0
	(1..factor.size).each{|n|
		factor.combination(n){|a|
			divisor=a.reduce(:lcm)
			items=ma/divisor
			items_sum=items*(items+1)/2
			r+=(-1)**(~n%2) * items # _sum*divisor
		}
	}
	r
end
m=gets.to_i
factor=gets.split.map(&:to_i)
p solve(factor,m)