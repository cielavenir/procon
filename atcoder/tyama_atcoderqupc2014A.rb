#!/usr/bin/ruby
a,b,c,d=gets.split.map(&:to_i)
p c.times.map{gets.split.map(&:to_i).sort_by(&:-@)[b-1]}.sort_by(&:-@)[d-1]