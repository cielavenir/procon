#!/usr/bin/ruby
n,k=gets.split.map &:to_i
r=0
(k+1..n).each{|i|r+=(i-k)*(n/i)+[n%i-k+1,0].max}
p k<1?n*n :r
