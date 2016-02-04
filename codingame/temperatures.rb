#!/usr/bin/ruby
gets;p gets.split.map(&:to_i).min_by{|e|[e.abs,-e]}||0