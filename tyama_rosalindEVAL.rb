#!/usr/bin/ruby
n=gets.to_i
s=gets.chomp
puts gets.split.map{|e|p=e.to_f;((p/2)**s.scan(/[GC]/).count*(0.5-p/2)**s.scan(/[AT]/).count)*(n-s.size+1)}*' '