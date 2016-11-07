#!/usr/bin/ruby
a,b,c=gets.split.map(&:to_i).sort;puts a+b==c ? :Yes : :No
