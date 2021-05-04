#!/usr/bin/ruby
h,w=gets.split.map &:to_i
ARGF.read.split.map(&:to_i).sort.each_slice(w).map{|e|puts e*' '}
