#!/usr/bin/ruby
p $<.drop(2).map{|e|e.split.map{|f|f.to_i*5+15}.reduce(:+)}.min