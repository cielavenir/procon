#!/usr/bin/ruby
N,K=gets.split.map(&:to_i)
a=[1,1]
2.step(N-1){|i|a<<a[i-2]*K+a[i-1]}
p a.last