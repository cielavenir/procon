#!/usr/bin/ruby
N,A,B,*X=`dd`.split.map &:to_i;r=0;X.each_cons(2){|x,y|r+=[B,A*(y-x)].min};p r
