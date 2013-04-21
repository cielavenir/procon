#!/usr/bin/ruby
p gets.to_i.times.reduce(0){|s|s+=gets.index('++')?1:-1}