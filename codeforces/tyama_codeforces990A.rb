#!/usr/bin/ruby
n,m,a,b=gets.split.map &:to_i
p [n%m*b,(m-n%m)*a].min
