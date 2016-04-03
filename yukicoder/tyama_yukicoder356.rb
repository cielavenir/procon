#!/usr/bin/ruby
a,b,c=$<.map &:to_i;$><<(b*c/(x=Rational(a*b,b-a))/(c-b)).numerator*x
__END__
a,b,c=$<.map &:to_i
x=1/(Rational(1,a)-Rational(1,b))
y=1/(Rational(1,b)-Rational(1,c))
puts (y/x).numerator*x