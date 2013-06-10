#!/usr/bin/ruby
puts$<.drop(1).to_a.sort_by(&:reverse)