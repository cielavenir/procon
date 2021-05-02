#!/usr/bin/ruby
p$<.map{|e|e.split.map &:to_i}.transpose.map{|x,y|x-y}.reduce :*
