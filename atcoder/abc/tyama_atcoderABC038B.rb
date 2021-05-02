#!/usr/bin/ruby
a=$<.map{|e|e.split.map(&:to_i)};puts a.pop.product(*a).any?{|x,y|x==y} ? :YES : :NO