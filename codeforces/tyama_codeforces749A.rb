#!/usr/bin/ruby
n=gets.to_i
p n/2
puts [*[2]*(n/2-1),2+n%2]*' '