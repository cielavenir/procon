#!/usr/bin/ruby
_,*a=$<.map &:chomp;puts a.uniq==a&&a.each_cons(2).all?{|x,y|x[-1]==y[0]} ? :Yes : :No
