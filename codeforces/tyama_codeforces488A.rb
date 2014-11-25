#!/usr/bin/ruby
N=gets.to_i
p (1..1/0.0).find{|i|(N+i).to_s.include?('8')}