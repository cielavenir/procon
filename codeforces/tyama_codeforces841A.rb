#!/usr/bin/ruby
n,k=gets.split.map &:to_i
h=Hash.new 0
gets.chomp.chars{|c|h[c]+=1}
puts h.values.any?{|e|e>k} ? :NO : :YES
