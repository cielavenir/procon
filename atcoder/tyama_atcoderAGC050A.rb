#!/usr/bin/ruby
N=gets.to_i
N.times{|i|puts '%d %d'%[(i*2-1)%N+1,(i*2)%N+1]}
