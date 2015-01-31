#!/usr/bin/ruby
require'prime';puts gets.to_i.prime_division.reduce(0){|s,(n,p)|s^p}>0 ? :Alice : :Bob
#require'prime';puts gets.to_i.prime_division.reduce(0){|s,e|s^e[1]}>0?'Alice': :Bob