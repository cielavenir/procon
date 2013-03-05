#!/usr/bin/ruby
a=gets.to_i.times.map{gets.split.map(&:to_i)}
a.each{|e|e<<e.reduce(:+)}
a=a.transpose
a.each{|e|e<<e.reduce(:+)}
a.transpose.each{|e|puts e*' '}