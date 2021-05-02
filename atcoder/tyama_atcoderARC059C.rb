#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i)
mi,ma=a.minmax
p (mi..ma).map{|e|a.map{|f|(f-e)**2}.reduce(:+)}.min