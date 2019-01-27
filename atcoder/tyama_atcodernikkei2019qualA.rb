#!/usr/bin/ruby
n,a,b=gets.split.map &:to_i
puts [[a,b].min,[a+b-n,0].max]*' '
