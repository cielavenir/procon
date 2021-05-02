#!/usr/bin/ruby
p gets.scan(/[ACGT]+/).map(&:size).max||0
