#!/usr/bin/ruby
x,y=gets.split.map &:to_i;p [[x,y,0],[-x,y,1],[x,-y,1],[-x,-y,2]].map{|a,b,c|a<=b ? b-a+c : 1e10}.min
