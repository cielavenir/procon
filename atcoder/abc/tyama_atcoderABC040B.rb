#!/usr/bin/ruby
p (1..n=gets.to_i).map{|i|(i-n/i).abs+n%i}.min