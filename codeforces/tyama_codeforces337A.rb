#!/usr/bin/ruby
n=gets.to_i
p gets.split.map(&:to_i).sort.each_cons(n).map{|e|e.last-e.first}.min