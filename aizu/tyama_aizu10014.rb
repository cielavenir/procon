#!/usr/bin/ruby
while(h,w=gets.split.map(&:to_i))!=[0,0]
h.times{|i|puts ((i&1==0?'#.':'.#')*w)[0,w]};puts end