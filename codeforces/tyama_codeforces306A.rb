#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
puts m.times.map{|i|n/m+(i<n%m ? 1 : 0)}*' '