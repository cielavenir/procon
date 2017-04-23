#!/usr/bin/ruby
require 'prime'
n,k=gets.split.map(&:to_i)
a=n.prime_division.flat_map{|n,p|[n]*p}
puts a.size<k ? -1 : (a[0,k-1]+[a[k-1..-1].reduce(:*)])*' '
