#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
p gets.split.map(&:to_f).sort[-k..-1].reduce(0){|s,e|s=(s+e)/2}