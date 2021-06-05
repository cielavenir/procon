#!/usr/bin/ruby
n,m=gets.split.map &:to_i
a=[[0,0]]+m.times.map{gets.split.map &:to_i}
puts a.each_cons(2).all?{|(a,b),(c,d)|(a-c).abs>=(b-d).abs}?"Yes":"No"
