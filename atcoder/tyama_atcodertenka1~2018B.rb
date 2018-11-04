#!/usr/bin/ruby
*a,k=gets.split.map &:to_i
k.times{|i|a[~i%2]+=a[i%2]/=2}
puts a*' '
