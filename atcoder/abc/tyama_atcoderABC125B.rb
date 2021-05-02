#!/usr/bin/ruby
gets;p$<.map{|e|e.split.map &:to_i}.transpose.map{|x,y|x-y}.select{|e|e>0}.reduce 0,:+
