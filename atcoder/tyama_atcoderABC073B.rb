#!/usr/bin/ruby
r=0;gets;$<.each{|e|a,b=e.split.map &:to_i;r+=b-a+1};p r
