#!/usr/bin/ruby
r=0
[0,*gets.chomp.bytes.map{|b|b-97}].each_cons(2){|x,y|r+=[(y-x)%26,(x-y)%26].min}
p r
