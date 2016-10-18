#!/usr/bin/ruby
h=Hash.new 0;n,k=gets.split.map &:to_i;p *n.times.map{|i|s,t,u=gets.split.map &:to_i;[-s,u,t,i]}.sort.map{|e|e[1]=h[e[1]]+=1;e}.sort.map(&:last)[0,k]
