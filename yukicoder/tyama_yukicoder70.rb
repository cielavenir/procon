#!/usr/bin/ruby
require'time';s=0;gets;$<.map{|e|x,y=e.split.map{|e|Time.parse e};y-=x;s+=y<0?86400+y : y};p s.to_i/60