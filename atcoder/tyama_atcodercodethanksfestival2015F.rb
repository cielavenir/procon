#!/usr/bin/ruby
puts (gets.to_i%2*($<.count{|e|e.to_i<2}/2))>0??B:?A