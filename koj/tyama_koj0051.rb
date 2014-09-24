#!/usr/bin/ruby
puts gets.split.map{|e|e.to_i/2}.zip(gets.split.map{|e|e.to_i/2}).map{|a,b|a-b}*' '