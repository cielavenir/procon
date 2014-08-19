#!/usr/bin/ruby
p (11..999999).select{|i|i.to_s.chars.map{|e|(2..e.to_i).reduce(1,:*)}.reduce(:+)==i}.reduce(:+)