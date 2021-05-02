#!/usr/bin/ruby
gets;*a,b=gets.split.map(&:to_i).sort;puts a.reduce(:+)>b ? :Yes : :No
