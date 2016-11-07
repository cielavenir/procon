#!/usr/bin/ruby
p gets.chomp.split(/[AEIOUY]/).map(&:size).max.to_i+1
