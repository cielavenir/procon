#!/usr/bin/ruby
def fact(n) (1..n).reduce(:*)||1 end
gets.to_i.times{
	a,b=gets.split.map(&:to_i)
	p (fact(a+b-1)/fact(a)/fact(b-1)) % 1000000007
}