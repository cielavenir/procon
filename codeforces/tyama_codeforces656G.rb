#!/usr/bin/ruby
_,kitten,n=gets.split.map(&:to_i)
p $<.map{|e|e.chars.to_a}.transpose.count{|e|e.count('Y')>=n}