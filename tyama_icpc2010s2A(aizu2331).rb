#!/usr/bin/ruby
s=Array.new(100002,0)
gets.to_i.times{a,b=gets.split.map(&:to_i);s[a-1]+=1;s[b]-=1}
t=0;p 1.step(100000).reduce(0){|a,i|(t+=s[i])<i ? a : i}