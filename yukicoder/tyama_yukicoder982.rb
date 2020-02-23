#!/usr/bin/ruby
a,b=gets.split.map &:to_i
p a.gcd(b)>1?-1:~-a*~-b/2
