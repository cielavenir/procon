#!/usr/bin/ruby
a,d,m=gets.split.map(&:to_i)
x=m/a*d
p x.gcdlcm(a)==[d,m] ? x : -1