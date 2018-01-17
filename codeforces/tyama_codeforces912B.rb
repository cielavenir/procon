#!/usr/bin/ruby
n,k=gets.split.map &:to_i
p k==1 ? n : 2**n.to_s(2).size-1
