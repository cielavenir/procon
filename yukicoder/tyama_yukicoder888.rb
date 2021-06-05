#!/usr/bin/ruby
require'prime'
p gets.to_i.prime_division.reduce(1){|s,(n,p)|s*(n**(p+1)-1)/(n-1)}
