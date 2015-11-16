#!/usr/bin/ruby
require'prime';r=1;gets.to_i.prime_division.map{|n,p|r*=n**(p%2)};p r