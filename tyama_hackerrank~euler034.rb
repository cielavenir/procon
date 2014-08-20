#!/usr/bin/ruby
p (11..gets.to_i-1).select{|i|i.to_s.chars.map{|e|(2..e.to_i).reduce(1,:*)}.reduce(:+)%i==0}.reduce(0,:+)