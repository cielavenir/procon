#!/usr/bin/ruby
n,k=gets.split.map &:to_i
n-=2
r=0
#11.times{|i|5.times{|j|(8*i+9*j+4)%11==k&&r+=n/11+(i<n%11?1:0)}}
55.times{|i|(i/5*8+i%5*9+4)%11==k&&r+=n/11+(i/5<n%11?1:0)}
p r
