#!/usr/bin/ruby
a,b=2.times.map{gets;gets.split.map &:to_i};p a&b==b ? 1 : 0
