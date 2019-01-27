#!/usr/bin/ruby
s=0;gets;$<.map{|e|a,b=e.split.map &:to_i;s-=b;-a-b}.sort.each_slice(2){|x,y|s-=x};p s
