#!/usr/bin/ruby
require'matrix'
a,b,c,d=gets.split.map &:to_i
z=Matrix[[b,a],[c,b]].inv*Vector[c,d]
puts z[0]**2+4*z[1]<0?:I: :R