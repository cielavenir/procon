#!/usr/bin/ruby
require'prime';n,x=gets.split.map &:to_i;p x.prime_division.map{|m,k|m**(k/n)}.reduce 1,:*
