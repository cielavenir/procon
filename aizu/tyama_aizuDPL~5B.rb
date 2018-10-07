#!/usr/bin/ruby
a,b=gets.split.map &:to_i
p (b-a+1..b).reduce(:*)%(10**9+7)
