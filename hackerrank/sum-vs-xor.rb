#!/usr/bin/ruby
n=gets.to_i
p n==0 ? 1 : 1<<n.to_s(2).count(?0)
