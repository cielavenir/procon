#!/usr/bin/ruby
n=gets.to_i
M=$<.map{|e|e.split.map(&:to_i)}
n.times{|k|n.times{|i|n.times{|j|M[i][j]=[M[i][j],M[i][k]+M[k][j]].min}}}
p M.flatten.max