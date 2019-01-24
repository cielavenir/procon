#!/usr/bin/ruby
gets;r=x=0;gets.split.map(&:to_i).map{|y|x,r=y,r+[0,y-x].max};p r
