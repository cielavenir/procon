#!/usr/bin/ruby
M=10**9+7
n,m=gets.split.map &:to_i;r=0;s=[*0..n/m]
(2..n/m).each{|i|s[i]==i&&i.step(n/m,i){|j|s[j]=s[j]/i*~-i};r+=s[i]} # totient
r*=2;(2..n-2).each{|i|r=r*i%M}
p r
__END__
require 'prime'
M=1000000007
def fact(n)
	r=1
	(2..n).each{|i|r=r*i%M}
	r
end
def totient(n)
	n.prime_division.reduce(1){|s,e|s*(e[0]-1)*e[0]**(e[1]-1)}
end
n,m=gets.split.map &:to_i
p 2*fact(n-2)*(2..n/m).reduce(0){|s,i|s+totient(i)}%M
