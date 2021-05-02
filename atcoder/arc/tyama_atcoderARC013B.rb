#!/usr/bin/ruby
p$<.drop(1).map{|e|e.split.map(&:to_i).sort}.transpose.map(&:max).reduce(:*)