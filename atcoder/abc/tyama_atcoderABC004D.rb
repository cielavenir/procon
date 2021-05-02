#!/usr/bin/ruby
R,G,B=gets.split.map &:to_i
p (-1000..1e3).map{|g|r=[g-R,-(R/2)-100].min;b=[g+G,-~-B/2+100].max;z=0;[[r+100,R],[g,G],[b-100,B]].map{|x,y|(x...x+y).map{|e|z+=e.abs}};z}.min
