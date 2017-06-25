#!/usr/bin/ruby
H,W,h,w=gets.split.map &:to_i;X=500
m=H.times.map{[X]*W}
(h-1).step(H-1,h){|i|(w-1).step(W-1,w){|j|m[i][j]=-(h*w-1)*X-1}}
s=0
H.times{|i|W.times{|j|s+=m[i][j]}}
puts *[s>0 ? ['Yes',*m.map{|e|e*' '}] : ['No']]
