#!/usr/bin/ruby
r=0;gets;gets.split.chunk{|e|e}.map{|k,v|r+=v.size/2};p r
