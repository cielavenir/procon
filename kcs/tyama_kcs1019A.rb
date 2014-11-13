#!/usr/bin/ruby
p gets.split.map(&:to_i).select{|e|e>0}.reduce(0,:+)