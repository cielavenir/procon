#!/usr/bin/ruby
a,b=gets.split.map &:to_i
puts (a..b).select{|i|i%3==0||i.to_s=~/3/}