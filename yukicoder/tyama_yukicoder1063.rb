#!/usr/bin/ruby
require 'prime'
a=b=1
gets.to_i.prime_division.each{|n,p|a*=n**(p/2);b*=n**(p%2)}
puts [a,b]*' '
