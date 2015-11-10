#!/usr/bin/ruby
p$<.read.split.map(&:to_i)[2..-1].each_slice(2).count{|x,y|x>0||y>0}