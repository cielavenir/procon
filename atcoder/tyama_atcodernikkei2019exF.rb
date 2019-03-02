#!/usr/bin/ruby
x=1789997546303
(1000-gets.to_i).times{x=[x/2,3*x+1][x%2]}
p x
