#!/usr/bin/ruby
gets;puts gets.split.map(&:to_i).sort.each_cons(3).any?{|x,y,z|x+y>z}?:YES: :NO
