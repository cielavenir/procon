#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i;puts a.abs>b*c ? :No : :Yes
