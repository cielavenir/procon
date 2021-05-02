#!/usr/bin/ruby
n,k,*a=`dd`.split.map &:to_i;r=0;a.map{|e|r+=[k-e,e].min};p r*2
