#!/usr/bin/ruby
n,k=gets.split.map &:to_i
p n>=k ? 1<<n-k : 0
