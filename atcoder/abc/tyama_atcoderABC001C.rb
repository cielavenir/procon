#!/usr/bin/ruby
TABLE=['N','NNE','NE','ENE','E','ESE','SE','SSE','S','SSW','SW','WSW','W','WNW','NW','NNW']
WIND=[0,3,16,34,55,80,108,139,172,208,245,285,327]
deg,dis=gets.split.map(&:to_i)
wind=WIND.take_while{|e,i|(dis+3)/6>=e}.size-1
dir=wind==0 ? 'C' : TABLE[(deg+112)%3600/225]
puts dir+' '+wind.to_s