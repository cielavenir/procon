#!/usr/bin/ruby
w=gets.to_i;t=1,1;i=r=0;$<.map{|e|[-e.to_i,w<(i+=1)?0:1]}.sort.map{|c,f|t[f]+=1;r-=c*t[f^1]};p r
