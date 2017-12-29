#!/usr/bin/ruby
n,a,b=gets.split.map &:to_i
p (1..n).select{|i|k=i.to_s.bytes.map{|b|b-48}.reduce(:+);a<=k&&k<=b}.reduce(:+)
