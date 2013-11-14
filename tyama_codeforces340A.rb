#!/usr/bin/ruby
require 'rational'
x,y,a,b=gets.split.map(&:to_i)
g=x/x.gcd(y)*y
p b/g-(a-1)/g