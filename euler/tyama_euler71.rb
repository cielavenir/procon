#!/usr/bin/ruby
#ported from tyama_aizu2131.c
require 'rational'
def solve(a,b,d)
	p=Rational(a,b)
	a.step(d).map{|i|
		(i==b||(p*i).to_i.gcd(i)>1)?0:Rational((p*i).to_i,i)
	}.max
end
#p solve(3,7,1000000).numerator
gets.to_i.times{
	a,b,d=gets.split.map(&:to_i)
	r=solve(a,b,d)
	puts [r.numerator,r.denominator]*' '
}