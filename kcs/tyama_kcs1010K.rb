#!/usr/bin/ruby
require 'prime'
a=gets.to_i.prime_division
if a.size==1&&a[0][1]==1
	puts :PRIME
else
	puts a.map{|e|e[0].to_s+(e[1]==1?"":"^#{e[1]}")}*' '
end