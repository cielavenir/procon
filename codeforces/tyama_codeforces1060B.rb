#!/usr/bin/ruby
n=gets.to_i
k=n.to_s.size-1
p (n-('9'*k).to_i).to_s.chars.map(&:to_i).reduce(:+)+9*k
