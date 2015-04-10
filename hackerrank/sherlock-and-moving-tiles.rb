#!/usr/bin/ruby
l,x,y=gets.split.map(&:to_f)
gets.to_i.times{p Math.sqrt(2)*(l-Math.sqrt(gets.to_f))/(y-x).abs}