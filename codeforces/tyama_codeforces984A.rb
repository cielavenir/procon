#!/usr/bin/ruby
gets;a=gets.split.map(&:to_i).sort;p a[~-a.size/2]
