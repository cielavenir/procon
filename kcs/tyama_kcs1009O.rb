#!/usr/bin/ruby
require 'prime'
n,m=gets.split.map(&:to_i)
p gets.split.map(&:to_i).count{|e|(e+m).prime?}