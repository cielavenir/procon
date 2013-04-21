#!/usr/bin/ruby
a,x=$<.map{|e|e.split.map(&:to_i)};p x.permutation.map{|e|a.zip(e).map{|x,y|x/y}.reduce(:*)}.max