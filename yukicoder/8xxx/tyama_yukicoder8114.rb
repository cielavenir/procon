#!/usr/bin/ruby
n=gets.to_i
if n==2
  puts [0,:Yes]
elsif n%2==0
  puts [0,:No]
else
  puts [1,:No]
end
