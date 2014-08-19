#!/usr/bin/ruby
require 'prime'
n=gets.to_i
puts "#{n}: "+n.prime_division.map{|a,b|[a]*b*' '}*' '