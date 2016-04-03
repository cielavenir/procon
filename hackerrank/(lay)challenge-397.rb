#!/usr/bin/ruby
gets;puts$<.map{|e|e.split.map(&:to_i).each_cons(2).any?{|x,y|y==x}?:NO: :YES}