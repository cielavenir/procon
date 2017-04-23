#!/usr/bin/ruby
#https://oeis.org/A006753
require 'prime'
p Enumerator.new{|y|
	(2..1/0.0).each{|n|
		y<<n if !n.prime? && n.to_s.chars.map(&:to_i).reduce(:+) == n.prime_division.map{|x,y|y*x.to_s.chars.map(&:to_i).reduce(:+)}.reduce(:+)
	}
}.take(gets.to_i).last
