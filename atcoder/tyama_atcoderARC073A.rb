#!/usr/bin/ruby
puts gets.split.each_cons(2).all?{|x,y|x[-1]==y[0]}?:YES: :NO
