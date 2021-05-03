#!/usr/bin/ruby
n,m=gets.split.map &:to_i
p n>=m ? 0 : (1..n).reduce(1){|s,i|s*i%m}
