#!/usr/bin/ruby
n,m,a,b=gets.split.map &:to_i
x=[b]*n
m.times{l,r=gets.split.map &:to_i;(l-1...r).map{|i|x[i]=a}}
p x.reduce :+
