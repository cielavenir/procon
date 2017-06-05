#!/usr/bin/ruby
M=10**9+7;s=1
(1..gets.to_i).each{|i|s=s*i%M*(2*i-1)%M};p s
