#!/usr/bin/ruby
N=gets.to_i
A=$<.map{|e|e.split.map(&:to_i)}
a=[A[0][1],N-A[1][0]-A[2][0]].min
b=[A[1][1],N-a-A[2][0]].min
c=N-a-b
puts [a,b,c]*' '