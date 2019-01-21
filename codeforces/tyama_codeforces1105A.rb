#!/usr/bin/ruby
gets;a=gets.split.map &:to_i
c,t=(1..a.max).map{|t|[a.map{|x|[(t-x).abs-1,0].max}.reduce(:+),t]}.min
puts [t,c]*' '
