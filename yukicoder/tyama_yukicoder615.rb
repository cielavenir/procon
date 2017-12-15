#!/usr/bin/env ruby
n,k,*a=`dd`.split.map &:to_i;p a.sort.each_cons(2).map{|x,y|y-x}.sort[0..-k].reduce 0,:+
