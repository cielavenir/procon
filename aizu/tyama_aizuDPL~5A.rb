#!/usr/bin/ruby
a,b=gets.split.map &:to_i
p b**a%(10**9+7)
