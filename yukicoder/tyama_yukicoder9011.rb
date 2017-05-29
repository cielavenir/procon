#!/usr/bin/ruby
p gets.chomp.chars.map(&:to_i).reduce :+
