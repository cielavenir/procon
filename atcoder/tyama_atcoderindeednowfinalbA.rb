#!/usr/bin/ruby
p (gets.to_i..gets.to_i).reduce(0){|s,i|s+i*i*(i+1)/2}%1000000007