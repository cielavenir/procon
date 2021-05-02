#!/usr/bin/ruby
p gets.chomp.chars.each_cons(3).map{|a|(a.join.to_i-753).abs}.min
