#!/usr/bin/ruby
n=gets.to_i;puts 20.downto(1).select{|e|n[e-1]==1}*' '