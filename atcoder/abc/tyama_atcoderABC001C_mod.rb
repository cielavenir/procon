#!/usr/bin/ruby
x,y=gets.split.map(&:to_i)
w=[0,3,16,34,55,80,108,139,172,208,245,285,327].take_while{|e|(y+3)/6>=e}.size-1
puts (w==0?'C':['N','NNE','NE','ENE','E','ESE','SE','SSE','S','SSW','SW','WSW','W','WNW','NW','NNW'][(x+112)%3600/225])+" #{w}"