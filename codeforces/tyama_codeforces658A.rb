#!/usr/bin/ruby
(n,c),s,t=$<.map{|e|e.split.map(&:to_i)}
a,b=[n.times,(n-1).downto(0)].map{|e|x=y=0;e.each{|i|y+=[0,s[i]-c*x+=t[i]].max};y}
puts [:Tie,:Limak,:Radewoosh][a<=>b]