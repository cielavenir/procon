#!/usr/bin/ruby
n=gets.to_i
p (n-3..n).reduce(:*)/24%10**6