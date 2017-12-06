#!/usr/bin/ruby
n=gets.to_i;r=0;$<.map(&:to_f).sort.each_with_index{|e,i|r+=e*i/(2*n-1)};p r
