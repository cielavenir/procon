#!/usr/bin/ruby
n=gets.to_i-1
n=n-5>>1 while n>4
puts %w(Sheldon Leonard Penny Rajesh Howard)[n]
