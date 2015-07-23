#!/usr/bin/ruby
gets
m=gets.split.map(&:to_i).min-1
p m==0 ? -1 : 1