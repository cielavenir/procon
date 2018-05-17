#!/usr/bin/ruby
gets
p gets.split.map{|e|e.chars.uniq.sort}.uniq.size
