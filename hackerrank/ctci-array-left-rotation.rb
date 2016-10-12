#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
puts gets.split.rotate(k)*' '
