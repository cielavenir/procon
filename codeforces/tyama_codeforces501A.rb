#!/usr/bin/env ruby
a,b,c,d=gets.split.map(&:to_i)
e,f=[[a,c],[b,d]].map{|x,y|[75,250-y].max*x}
puts [:Vasya,:Tie,:Misha][(e<=>f)+1]