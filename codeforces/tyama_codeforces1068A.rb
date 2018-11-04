#!/usr/bin/ruby
n,m,k,l=gets.split.map &:to_i
x=(k+l+m-1)/m
p m*x>n ? -1 : x
