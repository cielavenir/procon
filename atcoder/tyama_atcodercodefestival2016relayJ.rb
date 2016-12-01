#!/usr/bin/ruby
N=gets.to_i
r=1.step(N-2,2).map{|i|[0,i]}
(N%2).step(N-1,2){|i|r<<[N-1,i]<<[i,N-1]}
1.step(N-2,3){|j|(1+j%2).step(N-2,2){|i|r<<[i,j]}}
p r.size
puts r.map{|e|e*' '}
