#!/usr/bin/ruby
a=(gets.to_i+1).times.map{x=0;y=0;gets.split[1].to_i.times{v,r=gets.split.map(&:to_f);x+=v*r;y+=r};x/y}
puts a.pop+1e-7<a.max ? :YES: :NO