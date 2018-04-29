#!/usr/bin/ruby
h=Hash.new 0;h[r=s=0]=1
gets
gets.split.map{|e|h[s+=e.to_i]+=1}
h.map{|_,e|r+=e*~-e/2};p r
