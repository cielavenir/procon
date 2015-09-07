#!/usr/bin/ruby
gets.to_i.times{p gets.split.map(&:to_i).reduce(:+)}