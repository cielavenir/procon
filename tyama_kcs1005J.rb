#!/usr/bin/ruby
require 'rational'
p gets.split.map(&:to_i).reduce(:gcd)