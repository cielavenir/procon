#!/usr/bin/ruby
n=gets.to_i
puts n%2==1 ? -1 : [*1..n].each_slice(2).map{|a,b|[b,a]}*' '