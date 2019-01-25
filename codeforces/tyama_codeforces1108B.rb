#!/usr/bin/ruby
n,*d=$<.read.split.map &:to_i
m=d.max
puts [m,d.select{|k|m%k>0||d.count(k)>1}.max]*' '
