#!/usr/bin/ruby
require'prime';p gets.to_i.prime_division.reduce(0){|s,(n,p)|s+(1..9).find{|i|i>=p-=i}}
