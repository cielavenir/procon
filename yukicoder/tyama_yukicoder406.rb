#!/usr/bin/ruby
gets;a=gets.split.map(&:to_i).sort.each_cons(2).map{|x,y|y-x}.uniq;puts a.size<2&&a[0]>0?:YES: :NO