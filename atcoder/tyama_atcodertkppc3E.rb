#!/usr/bin/ruby
n=gets.to_i;q=1.0;p n.times.map{|i|q=q*(n-i)/n}.reduce(:+)*-~n/2
