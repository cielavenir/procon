#!/usr/bin/ruby
gets;*a,b=gets.split.map(&:to_i).sort;p b+a.map{|e|e/2}.reduce(:+)
