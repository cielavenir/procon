#!/usr/bin/ruby
a,b=gets.split.map &:to_i
b/=b.gcd a
b/=2 while b%2<1
b/=5 while b%5<1
puts b<2 ? :No : :Yes
