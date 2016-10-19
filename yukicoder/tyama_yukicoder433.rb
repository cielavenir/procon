#!/usr/bin/ruby
f=->{gets.split.map &:to_i};h=Hash.new 0;n,k=f[];p *n.times.map{|i|s,t,u=f[];[-s,u,t,i]}.sort.sort_by{|e|e[1]=h[e[1]]+=1;e}.map(&:last)[0,k]
