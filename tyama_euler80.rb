#!/usr/bin/ruby
require 'bigdecimal'
p 1.step(100).select{|i|Math.sqrt(i).to_i**2!=i}.reduce(0){|s,i|s+=BigDecimal(i.to_s).sqrt(99).split[1][0..99].chars.map(&:to_i).reduce(&:+)}