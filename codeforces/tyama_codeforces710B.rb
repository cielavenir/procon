#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_i).sort
p a[~-n/2]