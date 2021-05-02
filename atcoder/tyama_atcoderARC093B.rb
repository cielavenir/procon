#!/usr/bin/ruby
N,D,r,*A=`dd`.split.map &:to_i
A.map{|e|r+=~-D/e+1};p r
