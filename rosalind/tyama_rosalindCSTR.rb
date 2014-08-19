#!/usr/bin/ruby
puts$<.map{|e|e.chomp.split''}.transpose.map{|l|l.instance_eval{map{|e,i|e==first ? 1:0}}*''}.select{|e|1<e.count('0')&&1<e.count('1')}