#!/usr/bin/ruby
gets;m=r=0;gets.split.map{|e|m<(k=e.to_i)&&(m=k;r+=1)};p r
