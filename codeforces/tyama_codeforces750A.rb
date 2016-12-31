#!/usr/bin/ruby
n,k=gets.split.map &:to_i
k=240-k
p ((1..n).find{|i|5*i*(i+1)/2>k}||n+1)-1
