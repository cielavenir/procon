#!/usr/bin/ruby
n,m=gets.split.map(&:to_i).sort
p m==1 ? 1 : n==1 ? m-2 : (n-2)*(m-2)
