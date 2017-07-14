#!/usr/bin/ruby
h={}
a,b=gets.split.map(&:to_i)
[*0.step(b*5,5)].product([*0..a]){|x,y|h[x+y]=1}
puts h.keys.sort[1..-1]
