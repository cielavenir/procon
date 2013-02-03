#!/usr/bin/ruby
p gets.split.reduce{|s,e|s+=e.to_i**2}