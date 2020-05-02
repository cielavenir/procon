#!/usr/bin/ruby
n,k=gets.split.map &:to_i
s=gets.chomp
puts s[k-1..-1]+s[0,k-1].send([:reverse,:to_s][n-k&1])
