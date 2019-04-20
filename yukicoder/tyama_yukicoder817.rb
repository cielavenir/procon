#!/usr/bin/ruby
K,*A=$<.map{|e|e.split.map &:to_i}
p (1..10**9).bsearch{|i|k=1;A.map{|a,b|k+=[0,[b,i].min-~-a].max};k>K[1]}
