#!/usr/bin/ruby
h={};a=[];gets.to_i.times{n=gets.to_i;a<<n;h[n]=1};h.keys.sort.each_with_index{|e,i|h[e]=i};puts a.map{|e|h[e]}