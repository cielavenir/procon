#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
p (n/2+n%2..n).find{|i|i%m==0}||-1