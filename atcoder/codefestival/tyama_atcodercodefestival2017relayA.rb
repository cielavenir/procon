#!/usr/bin/ruby
k,a,b=gets.split.map &:to_i
p a<=b ? a>=k ?1:-1:(k+~b)/(a-b)*2+1
