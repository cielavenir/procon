#!/usr/bin/ruby
require 'rational'
a,d=gets.split.map(&:to_i)
p=Rational(1,a+1);q=Rational(1,a);r=0
(a+2).step(d){|i|
	t=(p*i).to_i+1
	s=(q*i).to_i
	t.step(s){|j|
		if j.gcd(i)==1 then r+=1 end
	}
}
p r
__END__
2 12000