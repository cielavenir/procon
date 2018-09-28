#!/usr/bin/ruby
w=gets.chomp
r=0
while(s=gets.chomp)!='END_OF_TEXT'
s.downcase.split.each{|e|r+=e==w ?1:0}end
p r