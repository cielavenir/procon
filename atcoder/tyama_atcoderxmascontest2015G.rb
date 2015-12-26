#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i;r=0;a.each_cons(2){|x,y|r+=(x-y).abs};p r