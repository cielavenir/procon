#!/usr/bin/ruby
puts (1..gets.to_i).map{|i|s=(2..6).map{|j|i%j>0?'':(95+j).chr}*'';s.empty?? i:s}
