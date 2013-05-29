#!/usr/bin/ruby
n,k=gets.split(',')
s=1;k.to_i.times{|i|s=s*(n.to_i-i)/(i+1)};p s