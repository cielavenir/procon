#!/usr/bin/ruby
require'prime';gets;s=0;gets.split.each{|e|e.to_i.prime_division.map{|n,p|s^=p%3}};puts s>0?:Alice: :Bob