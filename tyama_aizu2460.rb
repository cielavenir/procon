#!/usr/bin/ruby
require'rational'
n,m=gets.split.map&:to_i
m.times{n=n.gcd gets.to_i}
puts n>1?'No':'Yes'