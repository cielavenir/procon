#!/usr/bin/ruby
n,a,b,c,d=gets.split.map(&:to_i)
p n*[0,n+[a+b,a+c,b+d,c+d].minmax.reduce(:-)].max