#!/usr/bin/ruby
n,m,*a=$<.read.split.map &:to_i
p m/a.select{|e|m%e<1}.max
