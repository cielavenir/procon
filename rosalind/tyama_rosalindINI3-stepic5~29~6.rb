#!/usr/bin/ruby
s=gets
puts gets.split.map(&:to_i).each_slice(2).map{|a,b|s[a..b]}*' '