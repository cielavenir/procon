#!/usr/bin/ruby
while(h,w=gets.split.map(&:to_i))!=[0,0]
h.times{|i|puts i==0||i==h-1?'#'*w :'#'+'.'*(w-2)+'#'};puts end