#!/usr/bin/ruby
n=gets.to_i
a=n.times.map{Hash[*gets.split.map(&:to_i)]}
a.each{|e|e.each{|k,v|a[0][k]=a.map{|_|_[k]||0}.min}}
puts a[0].select{|k,v|v>0}.sort*' '