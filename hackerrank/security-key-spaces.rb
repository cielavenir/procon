#!/usr/bin/ruby
s=gets.chomp
n=gets.to_i
puts s.bytes.map{|e|((e-48+n)%10+48).chr}*''