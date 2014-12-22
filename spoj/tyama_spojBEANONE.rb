#!/usr/bin/ruby
n=gets.to_i+3
p (1..n).reduce(:*)-n*n+1
#p n*((1..n-1).reduce(:*)-n)+1