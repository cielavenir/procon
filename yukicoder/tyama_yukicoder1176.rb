#!/usr/bin/ruby
A=gets.to_i
p (2..7).map{|i|Math.log(A,i).ceil*i}.min
