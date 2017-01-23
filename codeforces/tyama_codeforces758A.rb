#!/usr/bin/ruby
gets;a=gets.split.map(&:to_i);p a.max*a.size-a.reduce(:+)
