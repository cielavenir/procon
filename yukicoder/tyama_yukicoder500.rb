#!/usr/bin/ruby
n=gets.to_i
puts n>=50 ? '0'*12 : (s=(1..n).reduce(:*).to_s)[-[12,s.size].min..-1]
