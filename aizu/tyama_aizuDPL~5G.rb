#!/usr/bin/ruby
#Stirling 2
St2=[[1],[0,1]]
2.upto(1000){|n|St2<<[0,*St2[-1].each_cons(2).map.with_index(1){|(x,y),k|x+y*k},1]}
a,b=gets.split.map &:to_i
p (0..b).map{|k|St2[a][k].to_i}.reduce(0,:+)%(10**9+7)
