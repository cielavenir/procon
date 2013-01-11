#!/usr/bin/ruby
while s=gets do puts s.split(//).map{|e|e.to_i}.reduce(:+) end