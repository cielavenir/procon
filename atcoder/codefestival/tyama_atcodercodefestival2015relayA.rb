#!/usr/bin/ruby
n=gets.to_i
r=0
10.times{|i|r+=20*i+(i%2==0 ? n : 21-n)}
p r