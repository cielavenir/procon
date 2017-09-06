#!/usr/bin/ruby
n=gets.to_i
a=(n/2).downto(1).find{|i|i.gcd(n-i)<2}
puts '%d %d'%[a,n-a]
