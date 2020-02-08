#!/usr/bin/env crystal
M=14**6
a=[0]*-~M
(1..M).map{|i|(1..M//i).each{|j|a[i*j]+=1}}
a=(1..M).select{|i|a[i]==4}
p a[gets.not_nil!.to_i-1]
