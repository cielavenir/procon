#!/usr/bin/ruby
n,h,w,*a=$<.read.split.map &:to_i;r=0;a.each_slice(2){|x,y|r+=[x+y,w*2-x-y].min};p r*h
