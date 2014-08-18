#!/usr/bin/ruby
n=gets.split.map(&:to_i).min%2
puts ['Malvika','Akshat'][n]