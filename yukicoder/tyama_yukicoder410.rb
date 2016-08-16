#!/usr/bin/ruby
p $<.map{|e|e.split.map &:to_f}.transpose.map{|e|x,y=e.sort;(y-x)/2}.reduce :+