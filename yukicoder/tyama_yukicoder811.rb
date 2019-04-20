#!/usr/bin/ruby
require'prime'
n,k=gets.split.map &:to_i
r=t=0
o=Hash[n.prime_division]
(2...n).map{|i|
	s=1
	l=i.prime_division.sum{|n,p|s*=p+1;[o[n]||0,p].min}
	k<=l&&r<s&&(r=s;t=i)
}
p t
