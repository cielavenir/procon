#!/usr/bin/ruby
require 'rational'
p=Rational(1,3);q=Rational(1,2);r=0
4.step(12000){|i|
	t=(p*i).to_i+1
	s=(q*i).to_i
	t.step(s){|j|
		if j.gcd(i)==1 then r+=1 end
	}
}
p r