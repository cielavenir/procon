#!/usr/bin/ruby
require 'rational'
puts $<.drop(1).map{|e|e.split.map(&:to_i).reduce(&:gcdlcm).reverse.reduce(:/)}