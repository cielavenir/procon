#!/usr/bin/ruby
N=gets.to_i
a=$<.map{|e|e.split.map &:to_f}.transpose
puts [*1..N].sort_by{|i|a[i-1][1]*1.0/a[i-1][0]}*' '