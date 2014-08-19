#!/usr/bin/ruby
n,a,b,l=gets.split.map(&:to_f)
n.to_i.times{l-=(a-b)*l/a}
puts"%.9f"%l