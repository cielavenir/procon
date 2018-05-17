#!/usr/bin/ruby
n=gets.to_i
p n>1 ? n+1>>n%2 : n
