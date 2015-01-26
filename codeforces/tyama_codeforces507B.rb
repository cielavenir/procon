#!/usr/bin/env ruby
r,*_=gets.split.map(&:to_f)
d=Math.hypot(*_.each_slice(2).to_a.transpose.map{|e|e.reduce(:-)})
p (d/r/2).ceil