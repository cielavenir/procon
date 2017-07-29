#!/usr/bin/ruby
require'prime'
A,B,C=gets.split.map &:to_i
K=C==0?B: C
c=[[1,-1]]+K.abs.prime_division.map{|n,p|(0..p).map{|i|n**i}}
puts [0,*c.shift.product(*c).map{|_|_.reduce(1,:*)}].select{|x|x**3+A*x**2+B*x+C==0}.sort*' '
