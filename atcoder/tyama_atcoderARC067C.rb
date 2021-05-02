#!/usr/bin/ruby
require'prime';s=1;(1..gets.to_i).reduce(:*).prime_division.map{|n,p|s*=-~p};p s%(10**9+7)
__END__
#This solution accepts N=100000
require'prime';N=gets.to_i;s=1;Prime.each(N){|n|i=N;p=1;p+=i/=n while i>0;s*=p};p s%(10**9+7)
