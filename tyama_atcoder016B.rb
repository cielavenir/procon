#!/usr/bin/ruby
p $<.drop(1).map{|e|e.chomp.split('')}.transpose.map{|e|e.join.gsub(/o+/,'o').gsub('.','').size}.reduce(:+)||0