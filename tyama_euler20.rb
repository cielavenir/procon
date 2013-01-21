#!/usr/bin/ruby
p [*1..100].reduce(:*).to_s.chars.map(&:to_i).reduce(:+)