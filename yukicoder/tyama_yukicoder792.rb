#!/usr/bin/ruby
n=gets.to_i;a=$<.map{|e|e.split.map &:to_i}.select{|e|e[-1]==1}
puts 'A='+(a.size==2**n ? '⊤' : a.empty? ? '⊥' : a.map{|e|'('+n.times.map{|i|(e[i]==1 ? '' : '¬')+'P_%d'%(i+1)}*'∧'+')'}*'∨')
