#!/usr/bin/ruby
s=gets.chomp
n=gets.to_i-1
puts s[n/5,1]+s[n%5,1]