#!/usr/bin/ruby
puts$<.drop(1).map(&:reverse).sort.map(&:reverse)