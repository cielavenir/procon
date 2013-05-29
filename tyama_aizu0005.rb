#!/usr/bin/ruby
require'rational';while gets
a,b=$_.split.map &:to_i
puts a.gcdlcm(b)*' 'end