#!/usr/bin/ruby
require 'prime'
N,K=gets.split.map(&:to_i)
c=0;i=1
while i<N+K-1
	i+=1
    c=i.prime_division.size==K ? c+1:0
	p i-K+1 if c>=K
end