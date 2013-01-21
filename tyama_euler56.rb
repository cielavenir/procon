#!/usr/bin/ruby
p 1.step(99).map{|a|1.step(99).map{|b|(a**b).to_s.chars.map(&:to_i).reduce(:+)}.max}.max