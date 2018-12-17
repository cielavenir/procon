#!/usr/bin/ruby
h=gets.to_i;d=0;$<.map{|e|e.split.map &:to_i}.sort.map{|x,y|y+d==x&&d+=1;y+d<x&&(h=x-1;break)};p h
