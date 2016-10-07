#!/usr/bin/ruby
a,b=gets.split.map(&:to_i).minmax
p b-a
