#!/usr/bin/ruby
require 'rational'
p gets.to_i.times.map{
	a,b=gets.split.map(&:to_i)
	a.gcd(b)==1 ? [a,b].max : 0
}.reduce(:+)