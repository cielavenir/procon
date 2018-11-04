#!/usr/bin/ruby
require'prime';r=1;gets.to_i.prime_division.map{|n,k|r*=-~k};p r
