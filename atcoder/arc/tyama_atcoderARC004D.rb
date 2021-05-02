#!/usr/bin/ruby
require'prime'
N,M=gets.split.map &:to_i
p N.abs.prime_division.reduce(1){|s,(n,p)|
	s*(M..p+M-1).reduce(:*)/(1..p).reduce(:*)
}*2**~-M%1000000007