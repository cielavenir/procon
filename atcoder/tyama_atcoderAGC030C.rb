#!/usr/bin/ruby
K=gets.to_i
K<2&&(p 1,1;exit)
p N=(K+3)/4*2
N.times{|i|puts (0...N).map{|j|(i+j)%N+1+(i%2<1||(i+j)%N+N>=K ? 0:N)}*' '}
