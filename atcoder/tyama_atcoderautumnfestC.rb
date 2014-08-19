#!/usr/bin/ruby
n=gets.to_i;p gets.split.map(&:to_f).reduce(:+)/n*(n-1)