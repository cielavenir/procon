#!/usr/bin/ruby
B=gets.to_i
N=gets.to_i
C=$<.map(&:to_i).sort
T=[C[N/2],(C.reduce(:+)+B)/N].min
s=0
C.map{|e|s+=(e-T).abs}
p s