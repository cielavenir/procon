#!/usr/bin/ruby
require'set'
n,x,*a=`dd`.split.map &:to_i;s=Set.new(a);puts a.any?{|e|s.include?(e-x)} ? :Yes : :No
