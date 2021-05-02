#!/usr/bin/ruby
gets;a=$<.map &:to_i;p a.reduce(:+)-a.max/2
