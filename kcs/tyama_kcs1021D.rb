#!/usr/bin/ruby
require 'rational'
a,b=gets.split.map(&:to_i)
puts a.gcdlcm(b)*' '