#!/usr/bin/ruby
r=w=0;gets.reverse.chars{|c|c==?w?w+=1:c==?c?r+=w*~-w/2:0};p r