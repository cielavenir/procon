#!/usr/bin/ruby
gets;s=0
p gets.split.map(&:to_i).map.with_index(1){|e,i|(s+=e)/i}.min
