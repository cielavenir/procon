#!/usr/bin/ruby
a=gets.to_i.times.map{x,y=gets.split.map(&:to_i);y-x}
p a[0]>0&&a.all?{|e|e==a[0]} ? a[0] : -1