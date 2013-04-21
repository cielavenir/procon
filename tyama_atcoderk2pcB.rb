#!/usr/bin/ruby
n=gets.to_i;puts gets.split.map(&:to_i).sort[3,7].zip(n.times.map{gets.chop.split ''}.transpose.map{|e|e.join.split('-').map(&:size).max||0}.sort).any?{|e|e[0]<e[1]}?'NO':'YES'
#Ruby 1.9.2+ faster: e.chunk{|x|x=='X'?x:nil}.map{|x,a|a.size}.max||0