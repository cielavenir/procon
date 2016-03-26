#!/usr/bin/ruby
gets;a=gets.split.map(&:to_i).sort.uniq;puts a.each_cons(3).any?{|x,y,z|y-x==1&&z-y==1}?:YES: :NO