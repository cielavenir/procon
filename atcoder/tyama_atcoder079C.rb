#!/usr/bin/ruby
n=gets.to_i;h=Hash.new 0;print$<.none?{|e|a,b=e.split.map &:to_i;(a<2?h[b]+=1:b==n ?h[a]+=2:0)>2}?:IM:'',:POSSIBLE
