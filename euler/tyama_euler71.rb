#!/usr/bin/ruby
#ported from tyama_aizu2131.c
require 'rational'
p=Rational(3,7)
p 3.step(1000000).map{|i|
	(i==7||(p*i).to_i.gcd(i)>1)?0:Rational((p*i).to_i,i)
}.max.numerator