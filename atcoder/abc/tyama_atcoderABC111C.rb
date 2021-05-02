#!/usr/bin/ruby
n=gets.to_i
a=$<.map{|e|e.split.map &:to_i}
g=a.find{|x,y,h|h>0}
(0..100).each{|i|(0..100).each{|j|
	v=[g[2]+(g[0]-i).abs+(g[1]-j).abs,0].max
	puts [i,j,v]*' ' if a.all?{|x,y,h|h==[v-(x-i).abs-(y-j).abs,0].max}
}}
