#!/usr/bin/ruby
gets;a=(gets.split.map(&:to_i)+[1]).each_cons(2).select{|x,y|x>=y}.map{|x,y|x};p a.size;puts a*' '
