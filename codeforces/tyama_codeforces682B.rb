#!/usr/bin/ruby
r=1
gets;gets.split.map(&:to_i).sort.each{|e|e.to_i>=r&&r+=1}
p r