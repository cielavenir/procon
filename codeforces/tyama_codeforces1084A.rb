#!/usr/bin/ruby
r=0;[*$<][1].split.each_with_index{|e,i|r+=4*e.to_i*i};p r
