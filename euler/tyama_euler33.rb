#!/usr/bin/ruby
r=1
1.step(9){|a|1.step(9){|b|1.step(9){|d|r*=(Rational(10*a+d,10*d+b)==Rational(a,b))?Rational(a,b):1}}}
p r.denominator