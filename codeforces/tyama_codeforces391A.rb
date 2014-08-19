#!/usr/bin/ruby
p gets.chomp.chars.chunk{|c|c}.count{|e|e[1].size.even?}