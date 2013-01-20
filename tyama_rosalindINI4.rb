#!/usr/bin/ruby
a,b=gets.split.map(&:to_i)
p [*(a..b)].select{|e|e%2==1}.reduce(:+)