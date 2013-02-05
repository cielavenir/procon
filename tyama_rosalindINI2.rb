#!/usr/bin/ruby
p gets.split.reduce(0){|s,e|s+=e.to_i**2}