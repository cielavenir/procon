#!/usr/bin/ruby
S=gets.chomp
T='preferred'
p (0..S.size-T.size).map{|i|T.size.times.count{|j|S[i+j]!=T[j]}}.min