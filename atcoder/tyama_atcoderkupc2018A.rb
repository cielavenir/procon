#!/usr/bin/ruby
gets;p$<.map{|e|e.split.map &:to_i}.transpose.map{|a,b|a*b}.max
