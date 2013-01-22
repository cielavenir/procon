#!/usr/bin/ruby
s=gets.chomp
t=gets.chomp
i=0
puts t.chars.map{|e|i=s.index(e,i)+1}.join' '