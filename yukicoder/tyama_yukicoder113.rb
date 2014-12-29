#!/usr/bin/ruby
p Math.hypot(*gets.chomp.chars.map{|c|{?N=>[0,-1],?E=>[-1,0],?W=>[1,0],?S=>[0,1]}[c]}.transpose.map{|e|e.reduce(:+)})