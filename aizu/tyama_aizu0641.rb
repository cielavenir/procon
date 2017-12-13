#!/usr/bin/ruby
n,a,b,c,d=gets.split.map &:to_i
p [(n+a-1)/a*b,(n+c-1)/c*d].min
