#!/usr/bin/ruby
#draft: http://rosalind.info/problems/suggested/20/
def norm(a,b) a.zip(b).map{|e,f|(e-f)**2}.reduce(:+) end
puts $<.map{|e|e.split.map(&:to_f)}.combination(2).map{|a,b|'%.3f'%Math.sqrt(norm(a,b))}*' '