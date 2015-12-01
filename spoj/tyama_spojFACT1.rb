#!/usr/bin/ruby
require 'prime'
loop{
	n=gets.to_i
	break if n==0
	puts n.prime_division.map{|e|'%d^%d'%e}*' '
}