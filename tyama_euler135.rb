#!/usr/bin/ruby
require 'prime'
N=55992
s=0
inc=3
3.step(N,4){|n|
	s+=inc if n.prime?
	s+=inc-1 if (n+2).prime?
	inc=2 if n>N>>4
	inc=1 if n>N>>2
}
p s