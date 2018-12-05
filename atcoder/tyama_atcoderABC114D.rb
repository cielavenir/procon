#!/usr/bin/ruby
require'prime'
a=(1..gets.to_i).reduce(:*).prime_division
f=->m{a.count{|x,y|y>m}}
p f[73]+f[23]*~-f[1]+f[13]*~-f[3]+f[3]*~-f[3]*(f[1]-2)/2
