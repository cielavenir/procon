#!/usr/bin/ruby
n,x=gets.split.map &:to_i
a=$<.map{|e|e.split.map &:to_i}.sort_by{|a,b|-b}
a[0][0]+=x
p a.map{|a,b|a*b}.reduce :+
